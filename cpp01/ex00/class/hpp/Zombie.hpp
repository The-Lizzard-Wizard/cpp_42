#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string Pname);

		void	announce(void);
	private:
		std::string	name;
};

#endif