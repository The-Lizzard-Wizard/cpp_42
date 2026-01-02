#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void Add();
        int  confirm();
        void Search();
    private:
        Contact ContactList[8];
        int     NbContact;
};

#endif