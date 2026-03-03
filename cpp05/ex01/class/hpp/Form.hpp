#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string Pname);
		Form(std::string Pname, int PsignGrade, int PexecuteGrade);
		Form(Form &src);
		~Form();
		Form &operator=(Form &src);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void		beSigned(Bureaucrat &Bureau);
		bool		isSigned();
		std::string	getName();
		int	getsignGrade();
		int	getExectueGrade();
	private:
		const std::string	name;
		const int	signGrade;
		const int	executeGrade;
		bool		Signed;
};

std::ostream& operator<<(std::ostream& stream, Form &Pform);

#endif //FORM_HPP