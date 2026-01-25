#include "../hpp/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string pName) : Name(pName)
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 10;
	nbClap++;
}

ClapTrap::ClapTrap()
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 10;
	Name = "ClapTrap_" + nbClap;
	nbClap++;
}

ClapTrap::~ClapTrap()
{

}

std::string	ClapTrap::getName()
{

}

unsigned int ClapTrap::getHitPoint()
{

}

unsigned int ClapTrap::getEnergyPoint()
{

}

unsigned int ClapTrap::getAttackDamage()
{

}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}
