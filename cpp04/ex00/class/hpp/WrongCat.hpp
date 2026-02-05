#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat &src);
		WrongCat &operator=(WrongCat &src);
		~WrongCat();

		void makeSound() const;
	private:
};

#endif //WRONGCAT_HPP