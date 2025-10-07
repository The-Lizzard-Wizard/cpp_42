#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>

class Contact
{
    public:
        Contact() {
            FirstName = "";
            LastName = "";
            NickName = "";
            PhoneNumber = "";
            DarkestSecret = "";
        }
        Contact(std::string PFirstName, std::string PLastName,
            std::string PNickName, std::string PPhoneNumber,
            std::string PDarkestSecret) 
        {
            FirstName = PFirstName;
            LastName = PLastName;
            NickName = PNickName;
            PhoneNumber = PPhoneNumber;
            DarkestSecret = PDarkestSecret;
        }
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
};

class PhoneBook
{
    public:
        PhoneBook() {
            NbContact = 0;
            for (int i = 0; i < 8; i++)
            {
                ContactList[i] = Contact("", "", "", "", "");
            }
        }
        void Add();
        int  confirm();
        void Search();
    private:
        Contact ContactList[8];
        int     NbContact;
};

#endif