#include "../hpp/PhoneBook.hpp"
#include <string>
#include <iostream>

void Contact::DisplayContact()
{
	std::cout << "First name : " << FirstName << std::endl;
	std::cout << "Last name : " << LastName << std::endl;
	std::cout << "Nickname : " << NickName << std::endl;
	std::cout << "Phone number : " << PhoneNumber << std::endl;
	std::cout << "Darkest secret : " << DarkestSecret << std::endl;
}

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	DarkestSecret = "";
}
Contact::Contact(std::string PFirstName, std::string PLastName,
	std::string PNickName, std::string PPhoneNumber,
	std::string PDarkestSecret) 
{
	FirstName = PFirstName;
	LastName = PLastName;
	NickName = PNickName;
	PhoneNumber = PPhoneNumber;
	DarkestSecret = PDarkestSecret;
}

std::string Contact::get_info(std::string info)
{
	if (info == "FN")
		return (FirstName);
	else if (info == "LN")
		return (LastName);
	else if (info == "NN")
		return (NickName);
	return ("NI");
}
