#include "../hpp/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain;
}

Cat::Cat(Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain;
	for (int i = 0; i < 100; i++)
		brain->addIdea(src.getBrain()->getIdea(i), i);
}

Cat &Cat::operator=(Cat &src)
{
	std::cout << "Cat = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	for (int i = 0; i < 100; i++)
		this->brain->addIdea(src.getBrain()->getIdea(i), i);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Brain	*Cat::getBrain()
{
	return (brain);
}

void Cat::makeSound() const
{
	std::cout << "MIAO !!" << std::endl;
}