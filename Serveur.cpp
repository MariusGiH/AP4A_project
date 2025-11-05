#include "Serveur.h"
#include "badge.h"
#include <iostream>
#include <fstream>

void demandeAcces(const badge& b, const lecteur_badge& l, int heure, int minute) { //appele par lecteurBadge
    std::string verif;
    if(verifAccess(b, l) == 0) {
        verif = "permission accepted";
    }else if(verifAccess(b, l) == 1) {verif = "permission rejected : wrong function";} //Deux types de refus
    else{verif = "permission rejected : function lambda hasn't any access";}

    std::ofstream file("../log.csv", std::ios::app); //On ouvre le fichier log.csv pour enregistrer les nouvelles informations

    if (!file.is_open()) {
        std::cerr << "Erreur : impossible de trouver le fichier log.csv\n";
    }else {
        std::cout << "fichier des logs ouvert a " << heure << ":" << minute << "\n" << std::endl;
    }

    // Ecrire l'information
    file << heure << ":" << minute <<  ", " << b.getId() << ", " << b.getName() << ", "
    << b.getFunction() <<  ", " << l.getId() <<  ", " << l.getLocation() << ", " << verif << std::endl;

    file.close(); // fermeture du fichier
};

int verifAccess(const badge& b, const lecteur_badge& l) { //Ouvre le fichier autorisation.csv pour vérifier les droits de chaque fonctions de badge
    std::ifstream file("../autorisation.csv");
    std::string line;

    if (!file.is_open()) { //Verification que le fichier s'ouvre bien
        std::cerr << "Erreur : impossible d'ouvrir le fichier autorisation.csv\n";
    }else {
        std::cout << "Fichier autorisation ouvert\n";
    }

    std::getline(file, line); // on saute l'en-tête

    while (std::getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1); //Separation des lignes en fonction des ","

        std::string id = line.substr(0, pos1); //On associe un nom à chaque partie "decoupee" du fichier
        std::string function = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string pass1 = line.substr(pos2 + 1, pos3 - pos2 - 1);
        std::string pass2 = line.substr(pos3 + 1);

        // enlève les espaces possibles
        function.erase(0, function.find_first_not_of(" \t\r"));
        function.erase(function.find_last_not_of(" \t\r") + 1);
        pass1.erase(0, pass1.find_first_not_of(" \t\r"));
        pass1.erase(pass1.find_last_not_of(" \t\r") + 1);
        pass2.erase(0, pass2.find_first_not_of(" \t\r"));
        pass2.erase(pass2.find_last_not_of(" \t\r") + 1);

        if (function == b.getFunction()) {
            if (pass1 == l.getLocation() || pass2 == l.getLocation()) { //Verifie si la location du lecteur est dans les autorisations du badge
                return 0; //Accepte
            }else{return 1;} //Pas la bonne fonction
        }
    }
    file.close();
    return 2; // role pas trouvé
}
