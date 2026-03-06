#include "class/hpp/Bureaucrat.hpp"
#include "class/hpp/ShrubberyCreationForm.hpp"
#include "class/hpp/RobotomyRequestForm.hpp"
#include "class/hpp/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat solar("solar", 1);
	std::cout << "bureaucrat (" << solar << ") has been created" << std::endl;
	Bureaucrat hollow("hollow", 150);
	std::cout << "bureaucrat (" << hollow << ") has been created" << std::endl;

	std::cout << std::endl;

	PresidentialPardonForm Pform("hollow");
	ShrubberyCreationForm Sform("Dark root garden");
	RobotomyRequestForm Rform("hollow");

	std::cout << std::endl;
	hollow.signAForm(Pform);

	std::cout << std::endl;
	solar.signAForm(Pform);
	solar.signAForm(Sform);
	solar.signAForm(Rform);

	std::cout << std::endl;
	hollow.executeForm(Pform);
	
	std::cout << std::endl;
	solar.executeForm(Pform);
	solar.executeForm(Sform);

	std::cout << std::endl;
	solar.executeForm(Rform);
	solar.executeForm(Rform);
	solar.executeForm(Rform);
	solar.executeForm(Rform);
	solar.executeForm(Rform);

	std::cout << std::endl;
}