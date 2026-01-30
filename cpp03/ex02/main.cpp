#include <iostream>
#include "class/hpp/ClapTrap.hpp"
#include "class/hpp/FragTrap.hpp"
#include "class/hpp/ScavTrap.hpp"

int main(void)
{
	FragTrap	turbobot("turbo bot");
	ScavTrap	bot("bot");
	ClapTrap	megabot("mega bot");

	turbobot.highFivesGuys();
	bot.guardGate();
	bot.attack("mega bot");
	megabot.takeDamage(20);
	megabot.attack("bot");
	bot.takeDamage(0);
	bot.beRepaired(5);
}