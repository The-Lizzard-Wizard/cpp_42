#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
    public:
        Contact();
        Contact(std::string PFirstName, std::string PLastName,
            std::string PNickName, std::string PPhoneNumber,
            std::string PDarkestSecret);
        
        void DisplayContact();

        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
};

#endif