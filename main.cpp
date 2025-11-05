#include <fstream>
#include <iostream>
#include "Scheduler.h"

int main() {

    std::ofstream log("../log.csv", std::ios::trunc);  //Initialisation du log.csv

    if (!log.is_open()) {  //Initialisation du fichier log.csv
        std::cerr << "Erreur : impossible de trouver le fichier log.csv\n";
    }else {
        std::cout << "fichier des logs ouvert, demarrage simulation\n";
    }

    log << "Time, Id, Name, Function, IdLocation, Location, AuthorizedOrNot" << std::endl;
    log.close();

    simulation(); //lance simulation dans Scheduler

    return 0;

    //------------------------- Compte-rendu idées

    //Choix intentionnel de ne pas donner toutes les autorisations aux admins, pourrait se modifier très rapidement dans le fichier autorisation.csv
    //On pourrait ajouter le jour dans le log.csv, suffit de ne pas effacer à chaque redémarrage, et d'incrémenter une date à se moment avant de l'insérer au début de chaque ligne par exemple.
}
