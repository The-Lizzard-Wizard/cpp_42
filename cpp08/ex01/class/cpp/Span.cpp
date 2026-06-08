#include "../hpp/Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span()
{
	size = 0;
	nbReg = 0;
}

Span::Span(unsigned int N)
{
	size = N;
	nbReg = 0;
}

Span::Span(const Span &src)
{
	size = src.getSize();
	for (int i = 0; i < size; i++)
		array[i] = src.getVec()[i];
}

Span::~Span() { }


const char *Span::numberLimitReach::what() const throw()
{
	return ("number limit reach");
}

size_t Span::getSize() { return (size); }
size_t Span::getSize() const { return (size); }

void Span::addNumber(int num)
{
	nbReg++;
	if (nbReg > size)
	{
		nbReg--;
		throw numberLimitReach();
	}
	array.push_back(num);
	std::sort(array.begin(), array.end());
}

int Span::getBigNumPos()
{
	return (*std::max_element(array.begin(), array.end()));
}
int Span::getShortNumPos()
{
	return (*std::min_element(array.begin(), array.end()));
}

const std::vector<int> &Span::getVec() const
{
	return (array);
}

int Span::shortestSpan()
{
	int span = this->longestSpan();
	for (size_t i = 0; i < (size_t)nbReg - 1; i++)
		if (i < (size_t)nbReg)
			if ((array[i + 1] - array[i]) < span)
				span = array[i + 1] - array[i];
	return (span);
}

int Span::longestSpan()
{
	return (getBigNumPos() - getShortNumPos());
}
