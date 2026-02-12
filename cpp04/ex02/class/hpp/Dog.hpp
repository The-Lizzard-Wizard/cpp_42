#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog &src);
		Dog &operator=(Dog &src);
		~Dog();

		void makeSound() const;
		Brain	*getBrain();
	private:
		Brain *brain;
};

#endif //DOG_HPP