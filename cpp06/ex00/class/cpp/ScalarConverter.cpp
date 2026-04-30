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
	if (fmt.size() == 1 && isprint(fmt[0]) && !isdigit(fmt[0]))
		std::cout << "char: '" << fmt[0] << "'" << std::endl;
	else if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void PrintInt(std::string fmt)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (std::isnan(value) || std::isinf(value))
		std::cout << "int: " << fmt << std::endl;
	else if (value > std::numeric_limits<int>::max() ||
			value < std::numeric_limits<int>::min())
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

int pars(std::string &fmt, int &floatIndex)
{
	double value = std::strtod(fmt.c_str(), NULL);
	if (std::isnan(value) || std::isinf(value))
		return (0);
	if (fmt.size() <= 1)
		return (0);
	else
	{
		size_t i = 0;
		while (fmt[i] && isdigit(fmt[i]))
			i++;
		if (fmt[i] != '\0')
		{
			if (fmt[i] == 'f' && i == fmt.size() - 1)
				return (0);
			else if (fmt[i] == '.' && i != fmt.size() - 1)
			{
				i++;
				while (fmt[i] && isdigit(fmt[i]))
				{
					floatIndex++;
					i++;
				}
				if (fmt[i] == 'f' && i == fmt.size() - 1)
					return (0);
				return (0);
			}
			else
				return (1) ;
		}
		else
			return (0);
	}
}

void ScalarConverter::convert(std::string fmt)
{
	int floatIndex = 1;
	if (pars(fmt, floatIndex) == 1)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	if (floatIndex > 1)
		floatIndex--;
	std::cout << std::fixed << std::setprecision(floatIndex);
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
