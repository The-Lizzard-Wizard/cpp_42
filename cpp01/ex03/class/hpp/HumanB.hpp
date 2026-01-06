#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string pName);

		void attack();
		void setWeapon(Weapon &pWeapon);
	private:
		Weapon *hWeapon;
		std::string name;
};

#endif