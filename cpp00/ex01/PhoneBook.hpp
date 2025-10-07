#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>

class Contact
{
    public:
        Contact(std::string PFirstName, std::string PLastName,
            std::string PNickName, std::string PPhoneNumber,
            std::string PDarkestSecret);
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
};

class PhoneBook
{
    public:
        PhoneBook();
        Contact Add();
        void Search();
    private:
        Contact ContactList[8];
        int     NbContact;
};

#endif