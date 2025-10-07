#include "PhoneBook.hpp"
#include <string>

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