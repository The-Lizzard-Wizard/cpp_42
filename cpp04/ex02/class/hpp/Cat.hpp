#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat &src);
		Cat &operator=(Cat &src);
		~Cat();

		void makeSound() const;
		Brain	*getBrain();
	private:
		Brain *brain;
};

#endif //CAT_HPP