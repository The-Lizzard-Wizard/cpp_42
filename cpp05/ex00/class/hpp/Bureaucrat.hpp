#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

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
		void setName(std::string Pname);
		int getGrade();
		void setGrade(int Pgrade);

		void promot();
		void demot();
	private:
		std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat &Bureau);

#endif //BUREAUCRAT_HPP