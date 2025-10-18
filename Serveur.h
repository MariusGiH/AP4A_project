#ifndef SERVER_H
#define SERVER_H
#include "LecteurBadge.h"
#include "Badge.h"

//utilisation surcharge et polymorphisme : consigne
//config des droits d'accès faite au démarrage

class serveur{ //passive, elle ne fait que répondre aux demandes des autres class
private:
    std::string name;
public:
    std::string getName()const {return this->name;}
    void setName(std::string n){this->name = n;} //Pas const, car on va modifier le this
};

void demandeAcces(const badge& b, const lecteur_badge& l, int horaire);
int verifAccess(const badge& b, const lecteur_badge& l);


#endif //SERVER_H
