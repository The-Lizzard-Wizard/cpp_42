#include "class/hpp/Zombie.hpp"
#include "Zombie.h"

int main(void)
{
    Zombie *horde = zombieHorde(10, "Zombie");

    delete[] horde;
    return (0);
}