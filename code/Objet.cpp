#include <iostream>
#include "Objet.hpp"


//  Contructeur précis
Objet::Objet(Type t) : type(t) { }

Type Objet::getType() const
{
    return type;
}

std::string Objet::toString() const
{
    static const char* TypeNames[] = 
    {

        "Double Mise - Double le pot",
        "À POIL ! - dévoile la main ennemie",
        "Bonus Jetons - bonus de jetons",
        "Double Dollar$ - x2 sur vos dollars",
        "+1 défausse permanente - gagnez une défausse",
        "Aucun"
    };
    
    int idx = static_cast<int>(type);

    if (idx < 0 || idx >= 5) return "Aucun";

    return TypeNames[idx];
}


