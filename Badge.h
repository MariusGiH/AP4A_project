#ifndef BADGE_H
#define BADGE_H
#include <string>

class badge {
private:
    static int id_memory; //a initialiser | pour garder en mémoire quel était le dernier id donné
    int id_staff;
    std::string name;
    std::string function;
public: //forme de Coplien
    badge() : id_staff(id_memory++), name("no_name"), function("lambda") {} //Constructeur par défaut
    badge(const badge& b) : id_staff(b.id_staff), name(b.name), function(b.function) {} //Constructeur par copie
    badge(std::string name) : id_staff(id_memory++), name(name), function("lambda") {} //Constructeur
    badge(std::string name, std::string function) : id_staff(id_memory++), name(name), function(function) {}
    // badge operator=(const badge& b) {
    //     this->id_staff = b.id_staff;
    //     this->name = b.name;
    //     this->function = b.function;
    // } //Jsp si y'en as besoin
    ~badge(){}; //Destructeur, vide ou supprimé si inutil

    std::string getName()const {return this->name;};
    int getId()const {return this->id_staff;};
    std::string getFunction()const {return this->function;};
    void setName(std::string name){this->name = name;};
    void setId(int id){this->id_staff = id;};
    void setFunction(std::string function){this->function = function;};
};

class badge_student : public badge {
public:
    badge_student(const std::string& name)
        : badge(name, "student") {}
};

class badge_teacher : public badge {
public:
    badge_teacher(const std::string& name)
        : badge(name, "teacher") {}
};

class badge_security : public badge {
public:
    badge_security(const std::string& name)
        : badge(name, "security") {}
};

class badge_admin : public badge {
public:
    badge_admin(const std::string& name)
        : badge(name, "admin") {}
};

class badge_researcher : public badge {
public:
    badge_researcher(const std::string& name)
        : badge(name, "researcher") {}
};

//int badge::id_memory = 0;

#endif //BADGE_H
