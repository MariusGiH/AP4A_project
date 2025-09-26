#include "LecteurBadge.h"

#include <ostream>
#include <string>

std::string lecteur_badge::functionToString(access p) {
 switch (p) {
  case access::building:   return "Batiment principal";
  case access::classroom:   return "Salle de classe standart";
  case access::laboratory:       return "Laboratoire";
  case access::tech_room: return "Salle de la sécurité";
  case access::teach_room:  return "Salle des professeur";
  case access::admin_room:  return "Bureau des administrateurs";
 }
 return "Inconnu";
}