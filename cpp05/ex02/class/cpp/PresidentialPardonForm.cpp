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

}
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

}

std::string PresidentialPardonForm::getTarget() { return (target); }