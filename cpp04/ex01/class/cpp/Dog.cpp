#include "../hpp/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain;
	for (int i = 0; i < 100; i++)
		brain->addIdea(src.getBrain()->getIdea(i), i);
}

Dog &Dog::operator=(Dog &src)
{
	std::cout << "Dog = operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.type;
	for (int i = 0; i < 100; i++)
		this->brain->addIdea(src.getBrain()->getIdea(i), i);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Brain	*Dog::getBrain()
{
	return (brain);
}

void Dog::makeSound() const
{
	std::cout << "YAP YAP !!" << std::endl;
}