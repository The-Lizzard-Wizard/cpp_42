#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include "Contact.hpp"

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