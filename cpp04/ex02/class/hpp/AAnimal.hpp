#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal &src);
		AAnimal &operator=(AAnimal &src);
		virtual ~AAnimal();

		std::string getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string type;
};

#endif //AAnimal_HPP