#include "../hpp/Weapon.hpp"
#include <string>

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(std::string pType)
{
	type = pType;
}

std::string &Weapon::getType()
{
	std::string &typeREF = type;
	return (typeREF);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}