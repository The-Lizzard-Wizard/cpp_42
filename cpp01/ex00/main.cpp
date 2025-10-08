#include "class/hpp/Zombie.hpp"
#include "Zombie.h"

int main(void)
{
    Zombie *myZombie;

    myZombie = newZombie("bob le zombie");
    myZombie->announce();
    randomChump("jean le zombie");

    delete myZombie;
    return (0);
}