#include "../hpp/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = src.type;
}

WrongCat &WrongCat::operator=(WrongCat &src)
{
	std::cout << "WrongCat = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "OAIM !!" << std::endl;
}