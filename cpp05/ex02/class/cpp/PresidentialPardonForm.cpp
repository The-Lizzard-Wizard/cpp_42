#include "../hpp/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	target("target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string Ptarget) :
	AForm("PresidentialPardonForm", 25, 5),
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
		std::cout << executor.getName() << " execute " << AForm::getName() << std::endl;
		std::cout << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

std::string PresidentialPardonForm::getTarget() { return (target); }