#include <iostream>
#include "class/hpp/ClapTrap.hpp"

int main(void)
{
	ClapTrap	bot("bot");
	ClapTrap	megabot("mega bot");

	bot.attack("mega bot");
	megabot.takeDamage(0);
	megabot.attack("bot");
	bot.takeDamage(0);
	bot.beRepaired(5);
}