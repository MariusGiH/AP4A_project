#include "Scheduler.h"
#include "Serveur.h"
#include <iostream>
#include <fstream>#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include "Serveur.h"
#include "Badge.h"
#include "LecteurBadge.h"

void simulation() {
    serveur serveur_principal;

    // Creation des badges
    badge_student b1("marius");
    badge_teacher b2("célia");
    badge_security b3("armand");
    badge_admin b4("renaud");
    badge_researcher b5("augustin");

    std::vector<badge*> badges = {&b1, &b2, &b3, &b4, &b5};

    // Creation des lecteurs
    lecteur_badge_classroom l1;
    lecteur_badge_teach_room l2;
    lecteur_badge_tech_room l3;
    lecteur_badge_admin_room l4;
    lecteur_badge_laboratory l5;

    std::vector<lecteur_badge*> lecteurs = {&l1, &l2, &l3, &l4, &l5};

    // Generateur aleatoire
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> badge_dist(0, badges.size() - 1);
    std::uniform_int_distribution<> lecteur_dist(0, lecteurs.size() - 1);

    //Simulation horaire
    int heure = 8;       // début à 8h
    int minute = 0;      // initialisation a 0 minute
    const int pas_minutes = 30; // le pas est de 30minutes

    for (int i = 0; i < 19; ++i) { // de 8 a 19h
        badge& b = *badges[badge_dist(gen)];
        lecteur_badge& l = *lecteurs[lecteur_dist(gen)];

        // Appel de la fonction de vérification
        demandeAcces(b, l, heure, minute);

        // Avance le temps simulé
        minute += pas_minutes;
        if (minute >= 60) {
            minute -= 60;
            heure++;
        }
    }
}