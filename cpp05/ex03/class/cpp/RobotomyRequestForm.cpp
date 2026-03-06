#include "../hpp/RobotomyRequestForm.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	target("target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string Ptarget) :
	AForm("RobotomyRequestForm", 72, 45),
	target(Ptarget)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) :
	AForm(src.getName(), src.getsignGrade(), src.getExectueGrade()),
	target(src.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExectueGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " execute " << AForm::getName() << std::endl;
		static int seed = 0;
		time_t t;
		time(&t);
		srand(t + seed);
		seed++;
		std::cout << "brrzrzrzrzrzrzrz......" << std::endl;
		int r = rand()%2;
		if (r == 1)
			std::cout << target << " has been robotomized" << std::endl;
		else
			std::cout << "robotomization failed on " << target << std::endl;
	}
}

std::string RobotomyRequestForm::getTarget() { return (target); }