#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <cstddef>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(const MutantStack<T> &src);
		~MutantStack();
		MutantStack<T> &operator=(const MutantStack &src);

		typedef	typename std::stack<T>::container_type::iterator	iterator;

		iterator begin();
		iterator end();
	private :
};

#include "MutantStack.tpp"



#endif //MUTANTSTACK_HPP