#include "../hpp/AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	type = src.type;
}

AAnimal &AAnimal::operator=(AAnimal &src)
{
	std::cout << "AAnimal = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const { return (type); };