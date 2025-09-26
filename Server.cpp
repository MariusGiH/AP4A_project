#include "Server.h"
#include <iostream>
#include <map>

#include <string>

class badge;
class lecteur_badge;

bool server::verif_authorization(badge& a, lecteur_badge& b) {
//faudra noter l'horaire aussi
};

std::map <badge::function, std::vector<lecteur_badge::access>> authorization (badge& a, lecteur_badge& b) = {
    { badge::function::student , {lecteur_badge::access::classroom , lecteur_badge::access::building} },
    {badge::function::teacher , lecteur_badge::access::teach_room},
};