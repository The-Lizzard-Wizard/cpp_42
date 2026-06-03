#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src)
{

}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	if (*this != src)
	{
		*this = src;
	}
	return (*this);
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

#endif //MUTANTSTACK_TPP