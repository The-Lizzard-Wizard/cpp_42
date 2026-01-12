#include "class/hpp/harl.hpp"
#include <iostream>
#include <string>

int main()
{
    harl a;
    a.complain("DEBUG");
    a.complain("INFO");
    a.complain("WARNING");
    a.complain("ERROR");
}