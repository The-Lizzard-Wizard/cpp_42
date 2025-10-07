#include "../hpp/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int PhoneBook::confirm()
{
    std::string input;
    std::cout << "Are you sure you want to leave this field blank ? The contact cannot be saved. (y/n)";
    std::getline(std::cin, input);
    if (input.compare("y") == 0)
        return (1);
    return (0);
}

void PhoneBook::Add()
{
    std::string FirstName = "";
    std::string LastName = "";
    std::string NickName = "";
    std::string PhoneNumber = "";
    std::string DarkestSecret = "";
    while (1)
    {
        std::cout << "First name :";
        std::getline(std::cin, FirstName);
        if (FirstName.compare("") == 0)
        {
            if (confirm() == 1)
                return ;
        }
        else
            break ;
    }
    while (1)
    {
        std::cout << "Last name :";
        std::getline(std::cin, LastName);
        if (LastName.compare("") == 0)
        {
            if (confirm() == 1)
                return ;
        }
        else
            break ;
    }
    while (1)
    {
        std::cout << "Nickname :";
        std::getline(std::cin, NickName);
        if (NickName.compare("") == 0)
        {
            if (confirm() == 1)
                return ;
        }
        else
            break ;
    }
    while (1)
    {
        std::cout << "Phone number :";
        std::getline(std::cin, PhoneNumber);
        if (PhoneNumber.compare("") == 0)
        {
            if (confirm() == 1)
                return ;
        }
        else
            break ;
    }
    while (1)
    {
        std::cout << "DarkestSecret :";
        std::getline(std::cin, DarkestSecret);
        if (DarkestSecret.compare("") == 0)
        {
            if (confirm() == 1)
                return ;
        }
        else
            break ;
    }
    Contact NewContact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
    ContactList[NbContact] = NewContact;
    NbContact++;
    if (NbContact >= 8)
        NbContact = 0;
}

void PhoneBook::Search()
{
    std::string input;
    std::cout << "\e[1;95mid\e[0;36m" << std::setw(8) << "|";
    std::cout << "\e[1;95mfirst name\e[0;36m"<< "|";
    std::cout << "\e[1;95mlast name\e[0;36m" << std::setw(2) << "|";
    std::cout << "\e[1;95mnicknme\e[0;36m" << std::endl;
    std::cout << "===========================================" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::string FirstName = ContactList[i].FirstName;
        std::string LastName = ContactList[i].LastName;
        std::string NickName = ContactList[i].NickName;

        std::cout << i+1 << std::setw(9) << "|";
        if (FirstName.length() <= 10)
            std::cout << FirstName << std::setw((10 - FirstName.length()) + 1) << "|";
        else
        {
            std::cout << FirstName.substr(0, 9) << "." << "|";
        }
        if (LastName.length() <= 10)
            std::cout << LastName << std::setw((10 - LastName.length()) + 1) << "|";
        else
        {
            std::cout << LastName.substr(0, 9) << "." << "|";
        }
        if (NickName.length() <= 10)
            std::cout << NickName << std::endl;
        else
        {
            std::cout << NickName.substr(0, 9) << "." << std::endl;;
        }
    }
    std::cout << "\e[0mSelect a Contact\n>";
    std::getline(std::cin, input);
}
