#ifndef SERVER_H
#define SERVER_H
#include "LecteurBadge.h"
#include "Badge.h"
#include "fstream"
#include "iostream"


//utilisation surcharge et polymorphisme : consigne
//config des droits d'accès faite au démarrage

class serveur{ //passive, elle ne fait que répondre aux demandes des autres class
public:
    void demandeAcces(const badge& b, const lecteur_badge& l) { //envoyé par lecteurBadge
        std::ifstream file("../autorisation.csv");
        std::string line;

        if (!file.is_open()) {
            std::cerr << "Erreur : impossible d'ouvrir le fichier CSV\n";
        }else {
            std::cout << "Fichier CSV ouvert\n";
        }



        file.close();
    };

};



#endif //SERVER_H
