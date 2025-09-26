#include "Badge.h"

#include <string>



std::string badge::functionToString(function p) {
    switch (p) {
        case function::student:   return "Etudiant";
        case function::teacher:   return "Professeur";
        case function::security:       return "Agent de securite";
        case function::admin: return "Administration";
        case function::researcher:  return "Chercheur";
    }
    return "Inconnu";
}