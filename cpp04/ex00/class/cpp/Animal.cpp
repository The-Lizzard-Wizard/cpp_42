#include "../hpp/Animal.hpp"
#include <iostream>

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = src.type;
}

Animal &Animal::operator=(Animal &src)
{
	std::cout << "Animal = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const { return (type); };

void Animal::makeSound() const
{
	std::cout << "\"Sound of an Animal\"" << std::endl;
}