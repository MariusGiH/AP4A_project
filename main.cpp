#include <fstream>
#include <iostream>
#include "Serveur.h"
#include "Scheduler.h"
#include "LecteurBadge.h"
#include "Badge.h"

int main() {

    std::ofstream log("../log.csv", std::ios::trunc);  //Initialisation du log.csv

    if (!log.is_open()) {
        std::cerr << "Erreur : impossible de trouver le fichier log.csv\n";
    }else {
        std::cout << "fichier des logs ouvert, demarrage simulation\n";
    }

    log << "Time, Id, Name, Function, IdLocation, Location, AuthorizedOrNot" << std::endl;
    log.close();

    simulation(); //lance simulation dans Scheduler

    return 0;

    //Tester methode virtuelle pure pour l'héritage

    //------------------------- Compte-rendu idées

    //Choix intentionnel de ne pas donner toutes les autorisations aux admins, pourrait se modifier très rapidement dans le fichier autorisation.csv
}
