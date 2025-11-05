#include <string>
#include <iostream>

int main(void)
{
    std::string BaseStr = "HI THIS IS BRAIN";
    std::string *stringPTR = &BaseStr;
    std::string &stringREF = BaseStr;

    std::cout << "======================================================" << std::endl;
    
    std::cout << "base string ptr : " << &BaseStr << std::endl;
    std::cout << "the stringPTR : " << stringPTR << std::endl;
    std::cout << "the ptr of the stringREF : " << &stringREF << std::endl;

    std::cout << "======================================================" << std::endl;

    std::cout << "base string : " << BaseStr << std::endl;
    std::cout << "stringPTR : " << *(stringPTR) << std::endl;
    std::cout << "stringREF : " << stringREF << std::endl;

    return (0);
}