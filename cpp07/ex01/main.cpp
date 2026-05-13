#include "iter.hpp"
#include <iostream>

int main()
{
	std::cout << "non const array=====================" << std::endl;
	int array[] = {1, 4, 10, 2};
	iter<int>(array, 4, printElem<int>);
	std::cout << "add 1 to each element in the array..." << std::endl;
	iter<int>(array, 4, add<int>);
	iter<int>(array, 4, printElem<int>);

	std::cout << std::endl << "const array=====================" << std::endl;
	const int const_array[] = {4, 5, 41, 8};
	iter<const int>(const_array, 4, printElem<int>);
}