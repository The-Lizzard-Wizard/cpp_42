#include "class/hpp/Bureaucrat.hpp"
#include "class/hpp/ShrubberyCreationForm.hpp"
#include "class/hpp/RobotomyRequestForm.hpp"
#include "class/hpp/PresidentialPardonForm.hpp"
#include "class/hpp/Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat solar("solar", 1);
	std::cout << "bureaucrat (" << solar << ") has been created" << std::endl;
	Bureaucrat hollow("hollow", 150);
	std::cout << "bureaucrat (" << hollow << ") has been created" << std::endl;

	std::cout << std::endl;
	Intern someRandomIntern;
	AForm* rrf;

	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;
	solar.signAForm(*rrf);

	std::cout << std::endl;
	solar.executeForm(*rrf);

	std::cout << std::endl;
	delete rrf;

	std::cout << std::endl;
	AForm* wf = NULL;
	try
	{
		wf = someRandomIntern.makeForm("formulaire A38", ":)))))");
	}
	catch(const std::exception& e)
	{
		std::cout << "someRandomIntern failed to create form : " << e.what() << '\n';
	}
}