#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string Ptarget);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm &src);
		void	execute(Bureaucrat const & executor) const;

		std::string getTarget();
	private:
		const std::string target;
};

#endif //ROBOTOMYREQUESTFORM_HPP