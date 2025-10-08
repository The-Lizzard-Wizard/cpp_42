#include "class/hpp/Zombie.hpp"

void  randomChump(std::string name)
{
    Zombie newZombie(name);
    newZombie.announce();
}