#include "../hpp/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) { (void)src; return (*this); }

ScalarConverter::~ScalarConverter() {}

void PrintChar(std::string fmt)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void PrintInt(std::string fmt)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (value > std::numeric_limits<int>::max() ||
			value < std::numeric_limits<int>::min() ||
			std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void PrintFloat(std::string fmt)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (std::isnan(value))
	{
		std::cout << "float: nanf\n";
	}
	else if (std::isinf(value))
	{
		if (value < 0)
		{
			std::cout << "float: -inff\n";
		}
		else
		{
			std::cout << "float: +inff\n";
		}
	}
	else if (value > std::numeric_limits<float>::max() ||
				value < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << "\n";
	}
	else
	{
		std::cout << "float: " << static_cast<float>(value) << "f\n";
	}
}

void PrintDouble(std::string fmt)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (std::isnan(value))
	{
		std::cout << "double: nan\n";
	}
	else if (std::isinf(value))
	{
		if (value < 0)
		{
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "double: +inf\n";
		}
	}
	else
	{
		std::cout << "double: " << static_cast<double>(value) << "\n";
	}
}


void ScalarConverter::convert(std::string fmt)
{
	std::cout << std::fixed << std::setprecision(1);
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
