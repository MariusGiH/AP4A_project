#ifndef LECTEURBADGE_H
#define LECTEURBADGE_H

#include <string>

class lecteur_badge{
private:
    static int id_memory;
    int id_entry;
    std::string location;
public: //forme de Coplien
    lecteur_badge() : id_entry(id_memory++), location("unknown"){};
    lecteur_badge(lecteur_badge& b) {this->id_entry = b.id_entry; this->location = b.location;}
    lecteur_badge(const std::string& location) : location(location){};
    lecteur_badge operator=(lecteur_badge& b) {
        this->id_entry = b.id_entry; this->location = b.location;
    }
    ~lecteur_badge();

    std::string getLocation(){return this->location;}
    int getId(){return this->id_entry;}
    void setLocation(const std::string& location){this->location = location;}
    void setId(int id){this->id_entry = id;}
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

int lecteur_badge::id_memory = 0;

#endif //LECTEURBADGE_H
