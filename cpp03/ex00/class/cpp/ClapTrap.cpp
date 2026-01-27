#include "../hpp/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string pName) : Name(pName)
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap()
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 10;
	Name = "ClapTrap";
}

ClapTrap::~ClapTrap() {}

std::string	ClapTrap::getName() { return (Name); }

unsigned int ClapTrap::getHitPoint() { return (HitPoint); }

unsigned int ClapTrap::getEnergyPoint() { return (EnergyPoint); }

unsigned int ClapTrap::getAttackDamage() { return (AttackDamage); }

void ClapTrap::attack(const std::string& target)
{
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << Name << " don't have enough enegy for attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	HitPoint -= amount;
	if (HitPoint < 0)
		HitPoint = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << "ClapTrap " << Name << " repairs itself" << std::endl;
	else
	{
		std::cout << "ClapTrap " << Name << " don't have enough enegy for repairs" << std::endl;
		return ;
	}
	HitPoint += amount;
}
