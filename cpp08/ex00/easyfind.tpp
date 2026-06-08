#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <algorithm>

const char *	ValueNotFoundException::what() const throw()
{
	return "Value Not Found.";
}

template <typename T>
int easyfind(T const &containers, int f)
{
	typename T::const_iterator it = std::find(containers.begin(), containers.end(), f);
		if (it != containers.end())
			return (*it);
	throw ValueNotFoundException();
}

#endif //EASYFIND_TPP