#include "../hpp/harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{}

void	Harl::Debug(void)
{
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::Info(void)
{
	std::cout <<   "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::Warning(void)
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::Error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::Complain(std::string level)
{
	void (Harl::*func_ptr)(void) = NULL;
	void (Harl::*func_array[])(void) = {&Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error};
	std::string level_array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int index = 0; index <= 4; index++)
		if (level.compare(level_array[index]) == 0)
			func_ptr = func_array[index];
	if(!func_ptr)
		return ;
	(this->*func_ptr)();
}
