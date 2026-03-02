#include "../hpp/Bureaucrat.hpp"
#include <iostream>

//============================================
//constructor/destructor

Bureaucrat::Bureaucrat() : name("bureaucrat"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Pname) : name(Pname), grade(150)
{
	std::cout << "Bureaucrat name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int Pgrade) : name("Bureaucrat")
{

	if (Pgrade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (Pgrade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = Pgrade;
	std::cout << "Bureaucrat grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Pname, int Pgrade) : name(Pname)
{
	if (Pgrade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (Pgrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = Pgrade;
	std::cout << "Bureaucrat name+grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &src)
{
	this->setName(src.getName());
	this->setGrade(src.getGrade());
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//============================================
//operator

Bureaucrat &Bureaucrat::operator=(Bureaucrat &src)
{
	if (this != &src)
	{
		this->setName(src.getName());
		this->setGrade(src.getGrade());
	}
	return (*this);
	std::cout << "Bureaucrat = operator called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat &Bureau)
{
	stream << Bureau.getName() << ", bureaucrat grade " << Bureau.getGrade();
	return (stream);
}

//============================================
//seter/geter

std::string Bureaucrat::getName() {return (name); }
void Bureaucrat::setName(std::string Pname) {name = Pname;}

int Bureaucrat::getGrade() { return (grade); }
void Bureaucrat::setGrade(int Pgrade)
{
	if (Pgrade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (Pgrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = Pgrade;
}

//============================================
//methode

void Bureaucrat::promot()
{
	if ((grade - 1) <= 0)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::demot()
{
	if ((grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

//============================================
//exception

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}