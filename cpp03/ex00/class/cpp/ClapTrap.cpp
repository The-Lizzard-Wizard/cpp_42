#include "../hpp/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	Name = "ClapTrap";
}

ClapTrap::ClapTrap(std::string pName) : Name(pName)
{
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	HitPoint = src.HitPoint;
	EnergyPoint = src.EnergyPoint;
	AttackDamage = src.AttackDamage;
	Name = src.Name;
}

ClapTrap::~ClapTrap() {}

ClapTrap &ClapTrap::operator=(ClapTrap &newClap)
{
	if (this == &newClap)
		return (*this);
	this->EnergyPoint = newClap.EnergyPoint;
	this->HitPoint = newClap.HitPoint;
	this->AttackDamage = newClap.AttackDamage;
	return (*this);
}

std::string	ClapTrap::GetName() { return (Name); }

unsigned int ClapTrap::GetHitPoint() { return (HitPoint); }

unsigned int ClapTrap::GetEnergyPoint() { return (EnergyPoint); }

unsigned int ClapTrap::GetAttackDamage() { return (AttackDamage); }

void ClapTrap::attack(const std::string& target)
{
	if (HitPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is die and can't attack " << target << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << Name << " don't have enough enegy for attack" << std::endl;
	if (EnergyPoint > 0)
		EnergyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	HitPoint -= amount;
	if (HitPoint < 0)
	{
		std::cout << "ClapTrap " << Name << " is die and can't take " << amount << " of damage" << std::endl;
		HitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << Name << " take " << amount << " of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is die and can't repairs itself" << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		std::cout << "ClapTrap " << Name << " repairs itself" << std::endl;
	else
	{
		std::cout << "ClapTrap " << Name << " don't have enough enegy for repairs" << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		EnergyPoint--;
	HitPoint += amount;
}
