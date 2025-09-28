#include <fstream>
#include <iostream>
#include "Serveur.h"
#include "Scheduler.h"
#include "LecteurBadge.h"
#include "Badge.h"

int main() {
    std::ifstream file("../autorisation.csv");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier CSV\n";
    }else {
        std::cout << "Fichier CSV ouvert\n";
    }

    simulation(); //lance simulation dans Scheduler

    //définir les class badge + lecteur_badge
    //tenter de les appeler dans serveur
    //vérifier à l'aide du csv si l'autorisation passe

    file.close();
    return 0;

    //Ajout d'un tri des autorisations en fonction des horaires
    //forme de Coplien pour les class

    //concept d’interface, m´ethodes virtuelles, conversions ascendantes

    //va lancer scheduler au demarrage
    //Il faut delete les objets à la fin + vider le log.csv
}
