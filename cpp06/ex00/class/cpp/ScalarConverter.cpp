#include "../hpp/ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) { return (*this); }

ScalarConverter::~ScalarConverter() {}

void PrintChar(str fmt)
{
}

void PrintInt(str fmt)
{
}

void PrintFloat(str fmt)
{
}

void PrintDouble(str fmt)
{
}

void ScalarConverter::convert(str fmt)
{
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
