#include "../hpp/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constroctor called" << std::endl;
	this->SetHitPoint(100);
	this->SetEnergyPoint(50);
	this->SetAttackDamage(20);
	this->SetName("ScavTrap");
}

ScavTrap::ScavTrap(std::string pName) : ClapTrap()
{
	std::cout << "ScavTrap name constroctor called" << std::endl;
	this->SetHitPoint(100);
	this->SetEnergyPoint(50);
	this->SetAttackDamage(20);
	this->SetName(pName);
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap()
{
	std::cout << "ScavTrap copy constroctor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {}

void ScavTrap::attack(const std::string& target)
{
	if (HitPoint <= 0)
	{
		std::cout << "ScavTrap " << Name << " is die and can't attack " << target << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " << Name << " don't have enough enegy for attack" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << " ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}