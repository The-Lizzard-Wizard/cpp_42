#include "../hpp/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.getIdea(i);
}

Brain &Brain::operator=(Brain &src)
{
	std::cout << "Brain = operator called" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = src.getIdea(i);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(std::string idea, int i)
{
	ideas[i] = idea;
}

void Brain::rmIdea(int i)
{
	ideas[i] = "";
}

std::string Brain::getIdea(int i)
{
	return (ideas[i]);
}

void Brain::printIdeas()
{
	for (int i = 0; i < 100; i++)
		if (ideas[i].compare("") != 0)
			std::cout << "idea " << i << " : " << ideas[i] << std::endl;
}
