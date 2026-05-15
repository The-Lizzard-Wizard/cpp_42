#include "class/hpp/Array.hpp"
#include <iostream>

template <typename T>
void print_array(Array<T> &arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
}

int main()
{
	Array<int> int_array(5);
	try
	{
		int_array[0] = 2;
		int_array[1] = 3;
		int_array[2] = 5;
		int_array[3] = 4;
		int_array[4] = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print_array(int_array);
	try
	{
		int_array[0] = 2;
		int_array[1] = 3;
		int_array[2] = 5;
		int_array[3] = 4;
		int_array[4] = 1;
		int_array[5] = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}