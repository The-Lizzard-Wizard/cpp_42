#include "../hpp/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	target("target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Ptarget) :
	AForm("ShrubberyCreationForm", 145, 137),
	target(Ptarget)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) :
	AForm(src.getName(), src.getsignGrade(), src.getExectueGrade()),
	target(src.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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

std::string ShrubberyCreationForm::getTarget() { return (target); }