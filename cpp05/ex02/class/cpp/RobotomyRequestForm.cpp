#include "../hpp/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 145, 137),
	target("target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string Ptarget) :
	AForm("RobotomyRequestForm", 145, 137),
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
		//execture code here
	}
}

std::string RobotomyRequestForm::getTarget() { return (target); }