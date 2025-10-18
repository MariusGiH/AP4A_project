#include "Scheduler.h"
#include "Serveur.h"
#include <iostream>
#include <fstream>

void simulation() {
    std::ofstream log("../log.csv", std::ios::trunc);

    if (!log.is_open()) {
        std::cerr << "Erreur : impossible de trouver le fichier log.csv\n";
    }else {
        std::cout << "fichier des logs ouvert, demarrage simulation\n";
    }

    log << "Time, Id, Name, Function, IdLocation, Location, AuthorizedOrNot" << std::endl;
    log.close();

    serveur serveur_principal;

    badge_student s1("marius");
    badge_admin s2("pierre");
    lecteur_badge_classroom c1;
    lecteur_badge_admin_room c2;

    //std::cout << s1.getName() << std::endl;

    demandeAcces(s1, c1, 18);
    demandeAcces(s2, c1, 18);
    demandeAcces(s1, c2, 18);
    demandeAcces(s2, c2, 18);
};



    //va definir la journee type en exemple

    //faire de l'aléatoire pour les horaires, les tentatives d'accès ?
