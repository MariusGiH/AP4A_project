#ifndef BADGE_H
#define BADGE_H
#include <string>


class badge { //faire de l'héritage, la personne lambda et
protected:
    static int id_staff; //a initialiser | pour garder en mémoire quel était le dernier id donné
    std::string name;
public:
    //Tout les premieres méthodes pour créer des nv badges
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

#endif //BADGE_H
