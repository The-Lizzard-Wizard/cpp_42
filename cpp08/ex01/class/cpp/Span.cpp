#include "../hpp/Span.hpp"
#include <iostream>

Span::Span()
{
	array = new int[0];
	size = 0;
	nbReg = 0;
}

Span::Span(unsigned int N)
{
	array = new int[N];
	size = N;
	nbReg = 0;
}

Span::Span(const Span &src)
{
	array = new int[src.getSize()];
	size = src.getSize();
	for (size_t i = 0; i < size; i++)
		array[i] = src[i];
}

Span::~Span() { delete[] array; }


const char *Span::numberLimitReach::what() const throw()
{
	return ("number limit reach");
}

size_t Span::getSize() { return (size); }
size_t Span::getSize() const { return (size); }

int &Span::operator[](unsigned long i)
{
	return (this->array[i]);
}

int &Span::operator[](unsigned long i) const
{
	return (this->array[i]);
}

static void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

static void sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}

void Span::addNumber(int num)
{
	array[nbReg] = num;
	nbReg++;
	sort(array, nbReg);
}

int Span::getBigNumPos()
{
	int pos = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > array[pos])
			pos = i;
	}
	return (pos);
}
int Span::getShortNumPos()
{
	int pos = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] < array[pos])
			pos = i;
	}
	return (pos);
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
	return (array[getBigNumPos()] - array[getShortNumPos()]);
}
