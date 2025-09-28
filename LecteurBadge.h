#ifndef LECTEURBADGE_H
#define LECTEURBADGE_H

#include <string>

class lecteur_badge{
private:
    static int id_entry;
};

class lecteur_badge_building {
    std::string location = "building";
public:
    friend class serveur;
};

class lecteur_badge_classroom {
    std::string location = "classroom";
public:
    friend class serveur;
};

class lecteur_badge_laboratory {
    std::string location = "laboratory";
public:
    friend class serveur;
};

class lecteur_badge_admin_room {
    std::string location = "admin_room";
public:
    friend class serveur;
};

class lecteur_badge_teach_room {
    std::string location = "teach_room";
public:
    friend class serveur;
};

class lecteur_badge_tech_room {
    std::string location = "tech_room";
public:
    friend class serveur;
};



#endif //LECTEURBADGE_H
