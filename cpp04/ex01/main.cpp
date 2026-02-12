#include <iostream>
#include "class/hpp/Animal.hpp"
#include "class/hpp/Cat.hpp"
#include "class/hpp/Dog.hpp"

int main()
{
	std::cout << "========== TEST 1: Polymorphism ==========\n";

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " says: ";
	dog->makeSound();

	std::cout << cat->getType() << " says: ";
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n========== TEST 2: Animal Array ==========\n";

	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "\n========== TEST 3: Deep Copy (Copy Constructor) ==========\n";

	Dog original;
	original.getBrain()->addIdea("Chase the mailman", 0);
	original.getBrain()->addIdea("Eat kibbles", 1);

	Dog copy(original); // copy constructor

	std::cout << "\nOriginal ideas:\n";
	original.getBrain()->printIdeas();

	std::cout << "\nCopy ideas:\n";
	copy.getBrain()->printIdeas();

	std::cout << "\nModifying original...\n";
	original.getBrain()->addIdea("Sleep all day", 0);

	std::cout << "\nOriginal ideas after modification:\n";
	original.getBrain()->printIdeas();

	std::cout << "\nCopy ideas (should remain unchanged if deep copy is correct):\n";
	copy.getBrain()->printIdeas();

	std::cout << "\n========== TEST 4: Assignment Operator ==========\n";

	Cat cat1;
	cat1.getBrain()->addIdea("Scratch the couch", 0);

	Cat cat2;
	cat2 = cat1; // assignment operator

	std::cout << "\nCat1 ideas:\n";
	cat1.getBrain()->printIdeas();

	std::cout << "\nCat2 ideas:\n";
	cat2.getBrain()->printIdeas();

	std::cout << "\nModifying cat1...\n";
	cat1.getBrain()->addIdea("Eat tuna", 0);

	std::cout << "\nCat1 ideas after modification:\n";
	cat1.getBrain()->printIdeas();

	std::cout << "\nCat2 ideas (should remain unchanged):\n";
	cat2.getBrain()->printIdeas();

	return 0;
}