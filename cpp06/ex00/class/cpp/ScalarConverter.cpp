#include "../hpp/ScalarConverter.hpp"
#include <iostream>
#include <sstream>

#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) { (void)src; return (*this); }

ScalarConverter::~ScalarConverter() {}


bool isFloatStr(str s)
{
	size_t i = 0;
	bool p = false;
	if (s.compare())
	if (s.c_str()[0] == '-')
		i++;
	if (s.c_str()[0] == '.')
		return (false);
	while (s.c_str()[i])
	{
		if (s.c_str()[i] == '.')
		{
			i++;
			p = !p;
			continue ;
		}
		if (s.c_str()[i] < 48 || s.c_str()[i] > 57)
			return (false);
		i++;
	}
	if (p == false)
		return (false);
	return (true);
}

bool isNumStr(str s)
{
	size_t i = 0;
	if (s.c_str()[0] == '-')
		i++;
	while (s.c_str()[i])
	{
		if (s.c_str()[i] < 48 || s.c_str()[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

void PrintChar(str fmt)
{
	str res = fmt;
	std::cout << "char : '" << res << "'" << std::endl;
}

void PrintInt(str fmt)
{
	str res;
	if (isFloatStr(fmt))
	{
		int si;
		std::istringstream(fmt) >> si;
		std::ostringstream oss;
		oss << si;
		res =  oss.str();
	}
	else if (isNumStr(fmt))
		res = fmt;
	else
		res = IMP;
	std::cout << "int : " << res << std::endl;
}

void PrintFloat(str fmt)
{
	str res;
	if (isFloatStr(fmt))
		res = fmt;
	else if (isNumStr(fmt))
		res = fmt;
	else
		res = "nan";
	std::cout << "float : " << res << "f" << std::endl;
}

void PrintDouble(str fmt)
{
	str res = fmt;
	std::cout << "double : " << res << std::endl;
}

void ScalarConverter::convert(str fmt)
{
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
