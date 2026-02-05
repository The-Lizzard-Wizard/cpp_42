#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog &src);
		Dog &operator=(Dog &src);
		~Dog();

		void makeSound() const;
	private:
};

#endif //DOG_HPP