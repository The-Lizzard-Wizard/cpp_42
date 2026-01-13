#include "class/hpp/harl.hpp"
#include <iostream>
#include <string>

int main()
{
    Harl a;
    a.Complain("DEBUG");
    a.Complain("INFO");
    a.Complain("WARNING");
    a.Complain("ERROR");
}