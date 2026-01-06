#include "../hpp/HumanA.hpp"
#include "../hpp/Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string pName, Weapon &pWeapon) : hWeapon(pWeapon)
{
	name = pName;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << hWeapon.getType() << std::endl;
}