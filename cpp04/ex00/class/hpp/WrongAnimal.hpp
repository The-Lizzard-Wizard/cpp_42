#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &src);
		WrongAnimal &operator=(WrongAnimal &src);
		virtual ~WrongAnimal();

		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};

#endif //WRONGANIMAL_HPP