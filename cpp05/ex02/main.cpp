#include "class/hpp/Bureaucrat.hpp"
#include "class/hpp/ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat solar("solar", 1);
	std::cout << "bureaucrat (" << solar << ") has been created" << std::endl;
	Bureaucrat hollow("hollow", 150);
	std::cout << "bureaucrat (" << hollow << ") has been created" << std::endl;

	std::cout << std::endl;

	ShrubberyCreationForm form("home");

	std::cout << std::endl;
}