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
    lecteur_badge(const lecteur_badge& b) {this->id_entry = b.id_entry; this->location = b.location;} //constructeur par recopie
    lecteur_badge(const std::string& location) : location(location){};
    // lecteur_badge operator=(const lecteur_badge& b) {
    //     this->id_entry = b.id_entry; this->location = b.location;
    // } //Jsp si y'en as besoin
    ~lecteur_badge(){};

    std::string getLocation()const {return this->location;}
    int getId()const {return this->id_entry;}
    void setLocation(const std::string& location){this->location = location;}
    void setId(int id){this->id_entry = id;}
};

class lecteur_badge_building : public lecteur_badge {
public:
    lecteur_badge_building() : lecteur_badge("building") {}
    
};

class lecteur_badge_classroom : public lecteur_badge {
public:
    lecteur_badge_classroom() : lecteur_badge("classroom") {}
};

class lecteur_badge_laboratory : public lecteur_badge {
public:
    lecteur_badge_laboratory() : lecteur_badge("laboratory") {}
    
};

class lecteur_badge_admin_room : public lecteur_badge {
public:
    lecteur_badge_admin_room() : lecteur_badge("admin_room") {}
    
};

class lecteur_badge_teach_room : public lecteur_badge {
public:
    lecteur_badge_teach_room() : lecteur_badge("teach_room") {}
    
};

class lecteur_badge_tech_room : public lecteur_badge {
public:
    lecteur_badge_tech_room() : lecteur_badge("tech_room") {}
    
};

//int lecteur_badge::id_memory = 0;

#endif //LECTEURBADGE_H
