#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string pName);
		FragTrap(FragTrap &src);
		~FragTrap();
		FragTrap &operator=(FragTrap &newScav);

		void highFivesGuys(void);
		void attack(const std::string& target);
	private:
};

#endif //FRAGTRAP_HPP