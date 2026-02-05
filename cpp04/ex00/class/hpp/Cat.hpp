#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat &src);
		Cat &operator=(Cat &src);
		~Cat();

		void makeSound() const;
	private:
};

#endif //CAT_HPP