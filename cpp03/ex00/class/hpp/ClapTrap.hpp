#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string pName);
		ClapTrap(ClapTrap &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &newClap);

		std::string	GetName();
		unsigned int GetHitPoint();
		unsigned int GetEnergyPoint();
		unsigned int GetAttackDamage();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string	Name;
		unsigned int HitPoint;
		unsigned int EnergyPoint;
		unsigned int AttackDamage;
};

#endif //CLAPTRAP_HPP