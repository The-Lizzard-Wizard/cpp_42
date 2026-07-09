#include "excep.hpp"

const char * notValidInput::what() const throw()
{
    return ("Error : not valid input");
}