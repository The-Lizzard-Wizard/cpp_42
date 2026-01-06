#include "../hpp/HumanB.hpp"
#include "../hpp/Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string pName)
{
	hWeapon = NULL;
	name = pName;
}

void	HumanB::setWeapon(Weapon &pWeapon)
{
	hWeapon = &pWeapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << hWeapon->getType() << std::endl;
}