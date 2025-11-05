
#include "class/hpp/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *Horde;

    Horde = new Zombie[N];
    (void)name;
    for (int i = 0; i < N; i++)
    {
        Horde[i].setName(name);
        Horde[i].announce();
    }
    return (Horde);
}