#include "../hpp/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constroctor called" << std::endl;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 10;
	Name = "ClapTrap";
}

ClapTrap::ClapTrap(std::string pName) : Name(pName)
{
	std::cout << "ClapTrap name constroctor called" << std::endl;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	std::cout << "ClapTrap copy constroctor called" << std::endl;
	HitPoint = src.HitPoint;
	EnergyPoint = src.EnergyPoint;
	AttackDamage = src.AttackDamage;
	Name = src.Name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &newClap)
{
	if (this == &newClap)
		return (*this);
	this->EnergyPoint = newClap.EnergyPoint;
	this->HitPoint = newClap.HitPoint;
	this->AttackDamage = newClap.AttackDamage;
	this->Name = newClap.Name;
	return (*this);
}

std::string	ClapTrap::GetName() { return (Name); }

unsigned int ClapTrap::GetHitPoint() { return (HitPoint); }

unsigned int ClapTrap::GetEnergyPoint() { return (EnergyPoint); }

unsigned int ClapTrap::GetAttackDamage() { return (AttackDamage); }

void ClapTrap::SetHitPoint(unsigned int amount) { HitPoint = amount; };

void ClapTrap::SetEnergyPoint(unsigned int amount) { EnergyPoint = amount; };

void ClapTrap::SetAttackDamage(unsigned int amount) {AttackDamage = amount; };

void ClapTrap::SetName(std::string pName) {Name = pName; };

void ClapTrap::attack(const std::string& target)
{
	if (HitPoint <= 0)
	{
		std::cout << "ClapTrap " << Name << " is die and can't attack " << target << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << Name << " don't have enough enegy for attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << Name << " is die and can't take " << amount << " of damage" << std::endl;
		return ;
	}
	if (amount > HitPoint)
	{
		std::cout << Name << " take " << amount << " of damage" << std::endl;
		HitPoint = 0;
	}
	else
	{
		std::cout << Name << " take " << amount << " of damage" << std::endl;
		HitPoint -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << Name << " is die and can't repairs itself" << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << Name << " repairs itself" << std::endl;
	else
	{
		std::cout << Name << " don't have enough enegy for repairs" << std::endl;
		return ;
	}
	HitPoint += amount;
}
