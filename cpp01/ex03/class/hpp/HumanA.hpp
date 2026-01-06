#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string pName, Weapon &pWeapon);

		void attack();
	private:
		Weapon &hWeapon;
		std::string name;
};

#endif