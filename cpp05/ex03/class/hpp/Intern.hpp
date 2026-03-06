#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &src);
		~Intern();

		Intern &operator=(Intern &src);

		class BadNameException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		AForm *makeForm(std::string Pform, std::string Ptarget);
		AForm *makeShrubbery(std::string Ptarget);
		AForm *makePardon(std::string Ptarget);
		AForm *makeRobotomy(std::string Ptarget);
	private:
};

#endif //INTERN_HPP