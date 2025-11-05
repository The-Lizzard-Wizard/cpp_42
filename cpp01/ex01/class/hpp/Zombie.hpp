#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string pName);

		void	announce(void);
		void	setName(std::string pName);
	private:
		std::string	name;
};

#endif