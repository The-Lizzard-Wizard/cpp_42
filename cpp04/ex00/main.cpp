#include <iostream>
#include "class/hpp/Animal.hpp"
#include "class/hpp/Cat.hpp"
#include "class/hpp/Dog.hpp"
#include "class/hpp/WrongAnimal.hpp"
#include "class/hpp/WrongCat.hpp"

int main()
{
	std::cout << "========== CORRECT POLYMORPHISM ==========\n";

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << animal->getType() << " says: ";
	animal->makeSound();

	std::cout << dog->getType() << " says: ";
	dog->makeSound();

	std::cout << cat->getType() << " says: ";
	cat->makeSound();

	delete animal;
	delete dog;
	delete cat;

	std::cout << "\n========== WRONG POLYMORPHISM ==========\n";

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongAnimal->getType() << " says: ";
	wrongAnimal->makeSound();

	std::cout << wrongCat->getType() << " says: ";
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}