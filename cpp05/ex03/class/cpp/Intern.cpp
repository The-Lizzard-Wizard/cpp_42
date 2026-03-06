#include "../hpp/Intern.hpp"
#include <iostream>
#include "../hpp/ShrubberyCreationForm.hpp"
#include "../hpp/RobotomyRequestForm.hpp"
#include "../hpp/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default construcor called" << std::endl;
}
Intern::Intern(Intern &src)
{
	(void)src;
	std::cout << "Intern copy construcor called" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeShrubbery(std::string Ptarget)
{
	ShrubberyCreationForm *form = new ShrubberyCreationForm(Ptarget);
	return (form);
}

AForm *Intern::makePardon(std::string Ptarget)
{
	PresidentialPardonForm *form = new PresidentialPardonForm(Ptarget);
	return (form);
}

AForm *Intern::makeRobotomy(std::string Ptarget)
{
	RobotomyRequestForm *form = new RobotomyRequestForm(Ptarget);
	return (form);
}


AForm *Intern::makeForm(std::string Pform, std::string Ptarget)
{
	AForm *form = NULL;
	std::string makeArrey[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm *(Intern::*makeArreyFunc[3])(std::string target) = {&Intern::makeShrubbery, &Intern::makePardon, &Intern::makeRobotomy};
	for (int i = 0; i < 3; i++)
	{
		if (Pform.compare(makeArrey[i]) == 0)
		{
			form = (this->*makeArreyFunc[i])(Ptarget);
			std::cout << "Intern creates " << makeArrey[i];
			return (form);
		}
	}
	throw Intern::BadNameException();
	return (NULL);
}

const char* Intern::BadNameException::what() const throw()
{
	return ("wrong form name");
}