#include <iostream>
#include "class/hpp/AAnimal.hpp"
#include "class/hpp/Cat.hpp"
#include "class/hpp/Dog.hpp"

int main()
{
	std::cout << "========== POLYMORPHISM TEST ==========\n";

	// AAnimal animal; 

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << " says: ";
	dog->makeSound();

	std::cout << cat->getType() << " says: ";
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n========== ARRAY TEST ==========\n";

	const int size = 4;
	AAnimal* animals[size];

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

	std::cout << "\n========== DEEP COPY TEST ==========\n";

	Dog original;
	original.getBrain()->addIdea("Guard the house", 0);
	original.getBrain()->addIdea("Eat food", 1);

	Dog copy(original); // Copy constructor

	std::cout << "\nOriginal ideas:\n";
	original.getBrain()->printIdeas();

	std::cout << "\nCopy ideas:\n";
	copy.getBrain()->printIdeas();

	std::cout << "\nModifying original...\n";
	original.getBrain()->addIdea("Sleep all day", 0);

	std::cout << "\nOriginal ideas after modification:\n";
	original.getBrain()->printIdeas();

	std::cout << "\nCopy ideas (should NOT change if deep copy works):\n";
	copy.getBrain()->printIdeas();

	std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n";

	Cat cat1;
	cat1.getBrain()->addIdea("Climb curtains", 0);

	Cat cat2;
	cat2 = cat1;

	std::cout << "\nCat1 ideas:\n";
	cat1.getBrain()->printIdeas();

	std::cout << "\nCat2 ideas:\n";
	cat2.getBrain()->printIdeas();

	std::cout << "\nModifying cat1...\n";
	cat1.getBrain()->addIdea("Eat fish", 0);

	std::cout << "\nCat1 ideas after modification:\n";
	cat1.getBrain()->printIdeas();

	std::cout << "\nCat2 ideas (should remain unchanged):\n";
	cat2.getBrain()->printIdeas();

	return 0;
}