#include "../hpp/PhoneBook.hpp"
#include <string>
#include <iostream>

void Contact::DisplayContact()
{
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
