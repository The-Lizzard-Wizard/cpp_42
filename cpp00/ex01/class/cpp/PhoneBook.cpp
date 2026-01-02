#include "../hpp/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook()
{
	NbContact = 0;
	for (int i = 0; i < 8; i++)
	{
		ContactList[i] = Contact("", "", "", "", "");
	}
}

int PhoneBook::confirm()
{
	std::string input;
	std::cout << "Are you sure you want to leave this field blank ? The contact cannot be saved. (y/n)";
	std::getline(std::cin, input);
	if (std::cin.eof())
			std::exit(1);
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
		if (std::cin.eof())
			std::exit(1);
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
		if (std::cin.eof())
			std::exit(1);
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
		std::getline(std::cin, LastName);
		if (std::cin.eof())
			std::exit(1);
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
		if (std::cin.eof())
			std::exit(1);
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
		if (std::cin.eof())
			std::exit(1);
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
		std::string FirstName = ContactList[i].get_info("FN");
		std::string LastName = ContactList[i].get_info("LN");
		std::string NickName = ContactList[i].get_info("NN");

		if (FirstName.compare("") != 0)
			std::cout << i+1 << std::setw(9) << "|";
		else
			std::cout << std::setw(10) << "|";
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
	std::cout << "\e[0mSelect a Contact ID:";
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(1);
	if (input.length() > 1 || isalnum(input.c_str()[0]) == 0 || ((atoi(input.c_str()) - 1) < 0 || (atoi(input.c_str()) - 1) > 7))
	{
		std::cout << "The ID must be a number between 1 and 8" << std::endl;
		return ;
	}
	if ((ContactList[atoi(input.c_str()) - 1].get_info("FN")).compare("") == 0)
	{
		std::cout << "There are no contact registered with this ID" << std::endl;
		return ;
	}
	ContactList[atoi(input.c_str()) - 1].DisplayContact();
}
