#include "../hpp/Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    name = "";
}

Zombie::Zombie(std::string Pname)
{
    name = Pname;
}

void	Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}