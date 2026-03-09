#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#define IMP "impoible"
#define NDIP "non displayable"

typedef std::string str;

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter &src);
		~ScalarConverter();

		static void convert(str fmt);
	private :
};

#endif //SCALARCONVERTER_HPP