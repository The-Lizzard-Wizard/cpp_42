#include "../hpp/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 145, 137),
	target("target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string Ptarget) :
	AForm("PresidentialPardonForm", 145, 137),
	target(Ptarget)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) :
	AForm(src.getName(), src.getsignGrade(), src.getExectueGrade()),
	target(src.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm() {}


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
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

std::string PresidentialPardonForm::getTarget() { return (target); }