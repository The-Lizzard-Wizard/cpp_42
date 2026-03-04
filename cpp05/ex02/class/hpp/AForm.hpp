#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string Pname);
		AForm(std::string Pname, int PsignGrade, int PexecuteGrade);
		AForm(AForm &src);
		~AForm();
		AForm &operator=(AForm &src);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void			beSigned(Bureaucrat &Bureau);
		bool			isSigned();
		bool			isSigned() const;
		std::string		getName();
		int				getsignGrade();
		int				getExectueGrade();
		int				getExectueGrade() const;

		virtual void	execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				Signed;
};

std::ostream& operator<<(std::ostream& stream, AForm &PAForm);

#endif //AFORM_HPP