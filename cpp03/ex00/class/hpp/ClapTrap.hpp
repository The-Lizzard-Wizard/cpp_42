
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string pName);
		~ClapTrap();
		//TO DO :
		//= operator

		std::string	getName();
		unsigned int getHitPoint();
		unsigned int getEnergyPoint();
		unsigned int getAttackDamage();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		static int nbClap = 0;
		std::string	Name;
		unsigned int HitPoint;
		unsigned int EnergyPoint;
		unsigned int AttackDamage;
};