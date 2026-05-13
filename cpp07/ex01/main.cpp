#include "iter.hpp"
#include <iostream>

int main()
{
	std::cout << "non const arrey=====================" << std::endl;
	int arrey[] = {1, 4, 10, 2};
	iter<int>(arrey, 4, printElem<int>);
	std::cout << "add 1 to each element in the array..." << std::endl;
	iter<int>(arrey, 4, add<int>);
	iter<int>(arrey, 4, printElem<int>);

	std::cout << std::endl << "const arrey=====================" << std::endl;
	const int const_arrey[] = {1, 4, 10, 2};
	iter<const int>(const_arrey, 4, printElem<int>);
}