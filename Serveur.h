#ifndef SERVER_H
#define SERVER_H
#include "LecteurBadge.h"
#include "Badge.h"

//utilisation surcharge et polymorphisme : consigne
//config des droits d'accès faite au démarrage

class serveur{ //passive, elle ne fait que répondre aux demandes des autres class
    public:
    void demandeAcces(const badge& b, const lecteur_badge& l); //reçue par lecteurBadge

};



#endif //SERVER_H
