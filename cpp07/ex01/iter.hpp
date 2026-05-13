#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arrey, int size, void (*func)(T &))
{
	for (int i = 0; i < size; i++)
	{
		func(arrey[i]);
	}
}

template <typename T>
void iter(const T *arrey, int size, void (*func)(const T &))
{
	for (int i = 0; i < size; i++)
	{
		func(arrey[i]);
	}
}

template <typename T>
void printElem(T &t)
{
	std::cout << t << std::endl;
}

template <typename T>
void printElem(const T &t)
{
	std::cout << t << std::endl;
}

template <typename T>
void add(T &t)
{
	t++;
}

#endif //ITER_HPP