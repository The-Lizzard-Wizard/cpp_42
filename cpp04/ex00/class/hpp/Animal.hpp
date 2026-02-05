#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		Animal(Animal &src);
		Animal &operator=(Animal &src);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};

#endif //ANIMAL_HPP