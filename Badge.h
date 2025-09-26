#ifndef BADGE_H
#define BADGE_H

#include <string>
#include <map>
#include <vector>

#include "Server.h"

class badge { //faire de l'héritage, la personne lambda et
    private:
    int id_staff;
    static int id; //a initialiser | pour garder en mémoire quel était le dernier id donné
    std::string name[20];
    enum class function{ student, teacher, security, admin, researcher }; //Il faut qu'on puisse associer plusieurs function


    public:
    friend class server;
    friend std::map <enum class a, std::vector<enum class b>> authorization (badge& a, lecteur_badge& b);
    std::string functionToString(function p);
    //mettre getter et setter

};

#endif //BADGE_H
