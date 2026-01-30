#include "../hpp/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constroctor called" << std::endl;
	this->SetHitPoint(100);
	this->SetEnergyPoint(100);
	this->SetAttackDamage(30);
	this->SetName("FragTrap");
}

FragTrap::FragTrap(std::string pName) : ClapTrap()
{
	std::cout << "FragTrap name constroctor called" << std::endl;
	this->SetHitPoint(100);
	this->SetEnergyPoint(100);
	this->SetAttackDamage(30);
	this->SetName(pName);
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap()
{
	std::cout << "FragTrap copy constroctor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap &newScav)
{
	if (this == &newScav)
		return (*this);
	this->AttackDamage = newScav.GetAttackDamage();
	this->HitPoint = newScav.GetHitPoint();
	this->EnergyPoint = newScav.GetEnergyPoint();
	this->Name = newScav.GetName();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (HitPoint <= 0)
	{
		std::cout << "FragTrap " << Name << " is die and can't attack " << target << std::endl;
		return ;
	}
	if (EnergyPoint > 0)
		EnergyPoint--;
	if (EnergyPoint > 0)
		std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "FragTrap " << Name << " don't have enough enegy for attack" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << Name << " say high Fives Guys!!" << std::endl;
}