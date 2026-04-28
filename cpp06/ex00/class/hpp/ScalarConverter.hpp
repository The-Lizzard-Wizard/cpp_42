#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#define IMP "impossible"
#define NDIP "non displayable"

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter &src);
		~ScalarConverter();

		static void convert(std::string fmt);
	private :
};

#endif //SCALARCONVERTER_HPP