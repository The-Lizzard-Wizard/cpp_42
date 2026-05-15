#include "../hpp/Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->s = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->s = n;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->arr = new T[src.size()];
	this->s = src.size();
	for (size_t i = 0; i < src.size(); i++)
		this->arr[i] = src[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->arr;
}

template <typename T>
T &Array<T>::operator[](unsigned long i)
{
	if (i >= this->size())
		throw OutOfBoundException();
	return (this->arr[i]);
}

template <typename T>
T const Array<T>::operator[](unsigned long i) const
{
	if (i >= this->size())
		throw OutOfBoundException();
	return (this->arr[i]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->s);
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("this Value is out of bound");
}
