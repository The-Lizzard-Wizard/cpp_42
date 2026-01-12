#include "../hpp/harl.hpp"
#include <iostream>
#include <string>

harl::harl()
{}

void	harl::DEBUG(void)
{
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	harl::info(void)
{
	std::cout <<   "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	harl::warning(void)
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	harl::error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void harl::complain(std::string level)
{
	void (harl::*func_ptr)(void) = NULL;
	void (harl::*func_array[])(void) = {&harl::DEBUG, &harl::info, &harl::warning, &harl::error};
	std::string level_array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int index = 0; index <= 4; index++)
		if (level.compare(level_array[index]) == 0)
			func_ptr = func_array[index];
	if(!func_ptr)
		return ;
	(this->*func_ptr)();
}
