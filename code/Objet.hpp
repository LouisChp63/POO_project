#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>

enum class Type
{

    DoubleMise=0,
	Apoil=1,
	BonusJetons=2,
    Fois2Dollars=3,
    Defausse=4,
    Aucun=5
};

class Objet
{
	private:
		Type type;
	public:
		virtual ~Objet(){}
		Objet() : type(Type::Aucun) {} // Constructeur par défault
		Objet(Type t);
		Type getType() const;
		std::string toString() const;
		
		//void utiliserObjet();
		
};

#endif
