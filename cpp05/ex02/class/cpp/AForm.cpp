#include "../hpp/AForm.hpp"
#include <string>
#include <iostream>

//==============================================
//construtor/destructor

AForm::AForm() : 
	name("AForm"),
	signGrade(150),
	executeGrade(150),
	Signed(false)
{
	std::cout << "Form default construtor called" << std::endl;
}

AForm::AForm(std::string Pname) :
	name(Pname),
	signGrade(150),
	executeGrade(150),
	Signed(false)
{
	std::cout << "Form name construtor called" << std::endl;
}

AForm::AForm(std::string Pname, int PsignGrade, int PexecuteGrade) :
	name(Pname),
	signGrade(PsignGrade),
	executeGrade(PexecuteGrade),
	Signed(false)
{
	std::cout << "Form name+signGrade+executeGrade construtor called" << std::endl;
}

AForm::AForm(AForm &src) :
	name(src.getName()),
	signGrade(src.getsignGrade()),
	executeGrade(src.getExectueGrade()),
	Signed(false)
{
	std::cout << "Form copy construtor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

//==============================================
//operator

AForm &AForm::operator=(AForm &src)
{
	if (this != &src)
		this->Signed = src.isSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, AForm &PAForm)
{
	stream << "Form (" << PAForm.getName() << ") sign Grade (" << PAForm.getsignGrade() << " execute Grade (" << PAForm.getExectueGrade() << ")";
	return (stream);
}

//==============================================
//exception

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

//==============================================
//methode

void		AForm::beSigned(Bureaucrat &Bureau)
{
	if (Bureau.getGrade() > signGrade)
		throw GradeTooLowException();
	else
		Signed = true;
}

bool		AForm::isSigned() { return (Signed); }

std::string	AForm::getName() { return (name); }

int	AForm::getsignGrade() { return (signGrade); }

int	AForm::getExectueGrade() { return (executeGrade); }
