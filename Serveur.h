#ifndef SERVER_H
#define SERVER_H
#include "LecteurBadge.h"
#include "Badge.h"

class serveur{ //passive, elle ne fait que répondre aux demandes des autres class
private:
    std::string name;
public:
    std::string getName()const {return this->name;}
    void setName(std::string n){this->name = n;} //Pas const, car on va modifier le this
};

void demandeAcces(const badge& b, const lecteur_badge& l, int heure, int minute);
int verifAccess(const badge& b, const lecteur_badge& l);


#endif //SERVER_H
