#include <iostream>
#include <string>
#include <algorithm>
#include "PhoneBook.hpp"


int main()
{
    std::string input;
    PhoneBook Book;
    while (1)
    {
        std::cout << ":";
        std::cin >> input;
        if (input.compare("EXIT") == 0)
            std::exit(0);
        if (input.compare("ADD") == 0)
            Book.Add();
        if (input.compare("SEARCH") == 0)
            Book.Search();
    }
}