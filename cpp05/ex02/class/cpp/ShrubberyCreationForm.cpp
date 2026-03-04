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

}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

}

std::string ShrubberyCreationForm::getTarget() { return (target); }