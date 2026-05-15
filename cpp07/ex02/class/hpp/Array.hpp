#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		T &operator[](unsigned long i);
		T const operator[](unsigned long i) const ;
		size_t size() const;
	private:
		size_t s;
		T *arr;
};

#include "../tpp/Array.tpp"

#endif //ARRAY_HPP