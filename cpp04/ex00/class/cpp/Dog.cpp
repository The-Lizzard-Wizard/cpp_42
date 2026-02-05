#include "../hpp/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = src.type;
}

Dog &Dog::operator=(Dog &src)
{
	std::cout << "Dog = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "YAP YAP !!" << std::endl;
}