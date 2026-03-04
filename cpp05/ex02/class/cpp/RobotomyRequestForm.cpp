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

}
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

}

std::string RobotomyRequestForm::getTarget() { return (target); }