#ifndef LECTEURBADGE_H
#define LECTEURBADGE_H

#include <string>

class lecteur_badge{
private:
    int id_entry;
    static int id_building, id_classroom, id_laboratory, id_tech_romm, id_teach_room, id_admin_room; //Pour un id s'incrémentant pour chaque type au lieu de mélanger

    enum class access{ building, classroom, laboratory, tech_room, teach_room, admin_room};

public:
    friend class server;
    std::string functionToString(access p);
};



#endif //LECTEURBADGE_H
