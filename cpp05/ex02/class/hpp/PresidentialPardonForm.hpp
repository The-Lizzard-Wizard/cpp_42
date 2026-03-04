#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string Ptarget);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm &src);
		void	execute(Bureaucrat const & executor) const;

		std::string getTarget();
	private:
		const std::string target;
};

#endif //PRESIDENTIALPARDONFORM_HPP