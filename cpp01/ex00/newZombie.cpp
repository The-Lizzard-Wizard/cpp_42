#include "../hpp/Zombie.hpp"

Zombie  *newZombie(std::string name)
{
    Zombie newZombie(name);
    return (&newZombie);
}