#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string Pname);
		Bureaucrat(int Pgrade);
		Bureaucrat(std::string Pname, int Pgrade);
		Bureaucrat(Bureaucrat &src);
		Bureaucrat &operator=(Bureaucrat &src);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string getName();
		std::string getName() const;
		int getGrade();
		int getGrade() const;
		void setGrade(int Pgrade);

		void promot();
		void demot();

		void signAForm(AForm &PAForm);
		void executeForm(AForm const & form) const;
	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat &Bureau);

#endif //BUREAUCRAT_HPP