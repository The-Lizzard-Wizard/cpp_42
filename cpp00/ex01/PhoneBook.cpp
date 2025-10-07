#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
    NbContact = 0;
    for (int i = 0; i < 8; i++)
    {
        ContactList[i] = Contact("", "", "", "", "");
    }
}

Contact PhoneBook::Add()
{
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;
    std::cout << "First name :";
    std::cin >> FirstName;
    std::cout << "Nick name :";
    std::cin >> NickName;
    std::cout << "Last name :";
    std::cin >> LastName;
    std::cout << "Phone number :";
    std::cin >> PhoneNumber;
    std::cout << "DarkestSecret :";
    std::cin >> LastName;
    Contact NewContact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
    return NewContact;
}

void PhoneBook::Search()
{
    std::cout << "search" << std::endl;
}
