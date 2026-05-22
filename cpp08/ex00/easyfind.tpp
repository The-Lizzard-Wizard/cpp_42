#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

const char *	ValueNotFoundException::what() const throw()
{
	return "Value Not Found.";
}

template <typename T>
int easyfind(T const &containers, int f)
{
	typename T::const_iterator it;
	for (it = containers.begin(); it != containers.end(); it++)
		if (*it == f)
			return (*it);
	throw ValueNotFoundException();
}

#endif //EASYFIND_TPP