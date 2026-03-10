#include "../hpp/ScalarConverter.hpp"
#include <iostream>
#include <sstream>

#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) { (void)src; return (*this); }

ScalarConverter::~ScalarConverter() {}

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

bool isFloatStr(str &s)
{
	size_t i = 0;
	bool p = false;
	//check overflow here
	if (s.c_str()[0] == '-')
		i++;
	if (s.c_str()[0] == '.')
		return (false);
	while (i < s.length() - 1)
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
	if (p == true && s.c_str()[i] == '.')
		return (false);
	else if (p == false && s.c_str()[i] == '.')
	{
		s += "0";
		return (true);
	}
	if (s.c_str()[i] == 'f')
	{
		char isn[2];
		isn[1] = '\0';
		isn[0] = s.substr(s.length() - 2, s.length() - 1).c_str()[0];
		if (p  && !isNumStr(isn))
			s = s.substr(0, s.length() - 1) + "0";
		else if (!p)
			s = s.substr(0, s.length() - 1) + ".0";
		return (true);
	}
	if (p == false)
		return (false);
	return (true);
}

bool isDoubleStr(str &s)
{
	size_t i = 0;
	bool p = false;
	//check overflow here
	if (s.c_str()[0] == '-')
		i++;
	if (s.c_str()[0] == '.')
		return (false);
	while (i < s.length() - 1)
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
	if (p == true && s.c_str()[i] == '.')
		return (false);
	else if (p == false && s.c_str()[i] == '.')
	{
		s += "0";
		return (true);
	}
	if (s.c_str()[i] == 'f')
	{
		char isn[2];
		isn[1] = '\0';
		isn[0] = s.substr(s.length() - 2, s.length() - 1).c_str()[0];
		if (p  && !isNumStr(isn))
			s = s.substr(0, s.length() - 1) + "0";
		else if (!p)
			s = s.substr(0, s.length() - 1) + ".0";
		return (true);
	}
	if (p == false)
		return (false);
	return (true);
}

void PrintChar(str fmt)
{
	str res;
	if (isNumStr(fmt) || isFloatStr(fmt))
	{
		char s[2];
		s[1] = '\0';
		int c;
		std::istringstream(fmt) >> c;
		s[0] = c;
		if (isprint(c))
			res = s;
		else
			res = NDIP;
	}
	else
		res = IMP;
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
		res = fmt + ".0";
	else
		res = "nan";
	if (res.c_str()[res.length() - 1] == 'f')
		std::cout << "float : " << res << std::endl;
	else
		std::cout << "float : " << res << "f" << std::endl;
}

void PrintDouble(str fmt)
{
	str res = fmt;
	if (isDoubleStr(fmt))
		res = fmt;
	else if (isNumStr(fmt))
		res = fmt + ".0";
	else
		res = "nan";
	std::cout << "double : " << res << std::endl;
}

void ScalarConverter::convert(str fmt)
{
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
