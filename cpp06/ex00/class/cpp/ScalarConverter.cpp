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
	float p = static_cast<float>(std::strtod(fmt.c_str(), NULL));
	std::cout << "float: " << std::fixed << std::setprecision(1) << p << "f" << std::endl;
}

void PrintDouble(std::string fmt)
{
	double p = static_cast<double>(std::strtod(fmt.c_str(), NULL));
	std::cout << "double: " << std::fixed << std::setprecision(1) << p << std::endl;
}


void ScalarConverter::convert(std::string fmt)
{
	PrintChar(fmt);
	PrintInt(fmt);
	PrintFloat(fmt);
	PrintDouble(fmt);
}
