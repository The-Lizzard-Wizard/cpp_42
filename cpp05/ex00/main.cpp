#include "class/hpp/Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat solar("solar", 1);
	std::cout << "bureaucrat (" << solar << ") has been created" << std::endl;
	Bureaucrat hollow("hollow", 150);
	std::cout << "bureaucrat (" << hollow << ") has been created" << std::endl;

	std::cout << std::endl;

	Bureaucrat Siegmeyer("Siegmeyer", 1);
	std::cout << "created Siegmeyer of catarina and try to promot him" << std::endl;
	try
	{
		Siegmeyer.promot();
	}
	catch(std::exception &e)
	{
		std::cout << "Siegmeyer " << e.what() << std::endl;;
	}

	std::cout << std::endl;

	Bureaucrat Pinwheel("Pinwheel", 150);
	std::cout << "created Pinwheet and try to demot him" << std::endl;
	try
	{
		Pinwheel.demot();
	}
	catch(std::exception &e)
	{
		std::cout << "Pinwheel " << e.what() << std::endl;
	}

	std::cout << std::endl;
}