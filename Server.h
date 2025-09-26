#ifndef SERVER_H
#define SERVER_H
#include "Badge.h"
#include "LecteurBadge.h"
#include <map>
#include <vector>

class server{
    public:

    bool verif_authorization(badge& a, lecteur_badge& b);//uniquement pointeur vers ce qu'il doit verifier pour ne pas les modifier

    std::map <badge::function, std::vector<lecteur_badge::access>> authorization;

};



#endif //SERVER_H
