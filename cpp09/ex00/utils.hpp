#ifndef UTILS_HPP
#define UTILS_HPP

#include <exception>
#include <string>
#include <sstream>
#include <map>

typedef std::string str;
typedef std::stringstream sstr;

class dateNotValidException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

class valueNotANumberException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

class fileOpenFailedException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

typedef struct s_date
{
	int year;
	int month;
	int day;
} t_date;

str fileToStr(str pathname);
str parsDate(str rawDate);
std::map<str, float> csvStrToMap(str src);
std::map<str, float> inputStrToMap(str src);

#endif //UTILS_HPP