#include "Serveur.h"
#include "badge.h"
#include <iostream>
#include <fstream>

void demandeAcces(const badge& b, const lecteur_badge& l, int horaire) {//envoyé par lecteurBadge
    std::string verif;
    if(verifAccess(b, l) == 0) {
        verif = "permission accepted";
    }else if(verifAccess(b, l) == 1) {verif = "permission rejected : wrong function";}
    else{verif = "permission rejected : function lambda hasn't any access";}

    std::ofstream file("../log.csv", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Erreur : impossible de trouver le fichier log.csv\n";
    }else {
        std::cout << "fichier des logs ouvert\n";
    }

    // Écrire l'information
    file << horaire  <<  ", " << b.getId() << ", " << b.getName() << ", "
    << b.getFunction() <<  ", " << l.getId() <<  ", " << l.getLocation() << ", " << verif << std::endl;

    file.close(); // fermeture du fichier
};

int verifAccess(const badge& b, const lecteur_badge& l) {
    std::ifstream file("../autorisation.csv");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier autorisation.csv\n";
    }else {
        std::cout << "Fichier autorisation ouvert\n";
    }

    std::getline(file, line); // on saute l'en-tête

    while (std::getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        std::string id = line.substr(0, pos1);
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
            if (pass1 == l.getLocation() || pass2 == l.getLocation()) { //Vérifie si la location du lecteur est dans les autorisations du badge
                return 0;
            }else{return 1;}
        }
    }
    file.close();
    return 2; // role pas trouvé
}


//écrire dans fichier log.csv, et si vide, ajouter première ligne : horaire, id_badge, id_lecteur, reponse_serveur


//faudra noter l'horaire aussi dans un fichier csv
