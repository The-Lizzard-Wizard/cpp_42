#include "../hpp/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = src.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &src)
{
	std::cout << "WrongAnimal = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const { return (type); };

void WrongAnimal::makeSound() const
{
	std::cout << "\"Sound of an WrongAnimal\"" << std::endl;
}