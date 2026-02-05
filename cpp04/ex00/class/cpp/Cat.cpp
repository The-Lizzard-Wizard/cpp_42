#include "../hpp/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = src.type;
}

Cat &Cat::operator=(Cat &src)
{
	std::cout << "Cat = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAO !!" << std::endl;
}