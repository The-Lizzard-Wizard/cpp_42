#ifndef EXCEP_HPP
#define EXCEP_HPP

#include <exception>

class notValidInput : public std::exception
{
	public:
		virtual const char * what() const throw();
};

#endif //EXCEP_HPP