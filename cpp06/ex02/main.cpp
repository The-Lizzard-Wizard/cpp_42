#include "class/hpp/A.hpp"
#include "class/hpp/B.hpp"
#include "class/hpp/C.hpp"
#include <iostream>
#include <cmath>

Base * generate(void)
{
	srand(time(NULL));
	int rnd = rand() % 3;
	if (rnd == 1)
		return (new A);
	else if (rnd == 2)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "is a A class" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "is a B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "is a C class" << std::endl;
}

void identify(Base& p)
{
	try {
		A &	a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "is A class" << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		B &	b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "is B class" << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		C &	c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "is C class" << std::endl;
	}
	catch(const std::exception& e) {}
}

int main()
{
	Base base;
	A a;
	B b;
	C c;
	identify(c);
}