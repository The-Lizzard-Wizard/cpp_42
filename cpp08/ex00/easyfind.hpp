#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class ValueNotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

template <typename T>
int easyfind(T const &containers, int f);

#endif //EASYFIND_HPP