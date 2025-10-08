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
    badge(badge& b) : id_staff(b.id_staff), name(b.name), function(b.function) {} //Constructeur par copie
    badge(std::string name) : id_staff(id_memory++), name(name), function("lambda") {} //Constructeur
    badge(std::string name, std::string function) : id_staff(id_memory++), name(name), function(function) {}
    badge operator=(badge& b) {
        this->id_staff = b.id_staff;
        this->name = b.name;
        this->function = b.function;
    }
    ~badge(); //Destructeur

    std::string getName(){return this->name;};
    int getId(){return this->id_staff;};
    std::string getFunction(){return this->function;};
    void setName(std::string name){this->name = name;};
    void setId(int id){this->id_staff = id;};
    void setFunction(std::string function){this->function = function;};
};

class badge_student : public badge {
private:
    std::string function = "student";
public:
    friend class serveur;
};

class badge_teacher : public badge{
private:
    std::string function = "teacher";
public:
    friend class serveur;
};

class badge_security : public badge{
private:
    std::string function = "security";
public:
    friend class serveur;
};

class badge_admin : public badge{
private:
    std::string function = "admin";
public:
    friend class serveur;
};

class badge_researcher : public badge{
private:
    std::string function = "researcher";
public:
    friend class serveur;
};

int badge::id_memory = 0;

#endif //BADGE_H
