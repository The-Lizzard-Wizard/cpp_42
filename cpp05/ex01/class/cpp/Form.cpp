#include "../hpp/Form.hpp"
#include <string>
#include <iostream>

//==============================================
//construtor/destructor

Form::Form() : 
	name("Form"),
	signGrade(150),
	executeGrade(150),
	Signed(false)
{
	std::cout << "Form default construtor called" << std::endl;
}

Form::Form(std::string Pname) :
	name(Pname),
	signGrade(150),
	executeGrade(150),
	Signed(false)
{
	std::cout << "Form name construtor called" << std::endl;
}

Form::Form(std::string Pname, int PsignGrade, int PexecuteGrade) :
	name(Pname),
	signGrade(PsignGrade),
	executeGrade(PexecuteGrade),
	Signed(false)
{
	std::cout << "Form name+signGrade+executeGrade construtor called" << std::endl;
}

Form::Form(Form &src) :
	name(src.getName()),
	signGrade(src.getsignGrade()),
	executeGrade(src.getExectueGrade()),
	Signed(false)
{
	std::cout << "Form copy construtor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

//==============================================
//operator

Form &Form::operator=(Form &src)
{
	if (this != &src)
		this->Signed = src.isSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, Form &Pform)
{
	stream << "Form (" << Pform.getName() << ") sign Grade (" << Pform.getsignGrade() << " execute Grade (" << Pform.getExectueGrade() << ")";
	return (stream);
}

//==============================================
//exception

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

//==============================================
//methode

void		Form::beSigned(Bureaucrat &Bureau)
{
	if (Bureau.getGrade() > signGrade)
		throw GradeTooLowException();
	else
		Signed = true;
}

bool		Form::isSigned() { return (Signed); }

std::string	Form::getName() { return (name); }

int	Form::getsignGrade() { return (signGrade); }

int	Form::getExectueGrade() { return (executeGrade); }
