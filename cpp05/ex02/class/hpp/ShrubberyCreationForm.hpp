#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string Ptarget);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm &src);
		void	execute(Bureaucrat const & executor) const;

		std::string getTarget();
	private:
		const std::string target;
};

#endif //SHRUBBERYCREATIONFORM_HPP