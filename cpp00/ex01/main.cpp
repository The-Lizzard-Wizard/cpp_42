#include <iostream>
#include <string>
#include <cstdlib>
#include "class/hpp/PhoneBook.hpp"


int main()
{
	std::string input;
	PhoneBook Book;
	while (1)
	{
		std::cout << ">";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
		if (input.compare("EXIT") == 0)
			std::exit(0);
		else if (input.compare("ADD") == 0)
			Book.Add();
		else if (input.compare("SEARCH") == 0)
			Book.Search();
	}
}