#include <iostream>
#include "class/hpp/Animal.hpp"
#include "class/hpp/Cat.hpp"
#include "class/hpp/Dog.hpp"
#include "class/hpp/WrongAnimal.hpp"
#include "class/hpp/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongI = new WrongCat();
	std::cout << WrongI->getType() << " " << std::endl;
	WrongI->makeSound();
	WrongMeta->makeSound();
	delete WrongMeta;
	delete WrongI;
	return (0);
}