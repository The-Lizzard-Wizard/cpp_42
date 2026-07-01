#include <map>
#include "utils.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <iostream>
#include <math.h>

const char * dateNotValidException::what() const throw()
{ return ("Error: invalid date."); }

const char * valueNotANumberException::what() const throw()
{ return ("Error: bad value registed in DB."); }

const char * fileOpenFailedException::what() const throw()
{ return ("Error: could not open file."); }

str fileToStr(str pathname)
{
	str res;
	std::ifstream file(pathname.c_str());
	if (!file.is_open())
		throw fileOpenFailedException();
	str line;
	while (getline(file, line))
		res += line += "\n";
	return (res);
}

str parsDate(str rawDate)
{
	str year(rawDate.substr(0, rawDate.find('-')));
	rawDate.erase(0, rawDate.find('-') + 1);
	str month(rawDate.substr(0, rawDate.find('-')));
	rawDate.erase(0, rawDate.find('-') + 1);
	str day(rawDate);
	if (year.find_first_not_of("1234567890") != str::npos)
		throw dateNotValidException();
	if (month.find_first_not_of("1234567890") != str::npos)
		throw dateNotValidException();
	if (day.find_first_not_of("1234567890") != str::npos)
		throw dateNotValidException();
	return (year + month + day);
}

t_date dateToStruct(str date)
{
	t_date structDate;
	sstr year(date.substr(0, 4));
	sstr month(date.substr(4,2));
	sstr day(date.substr(6,2));
	year >> structDate.year;
	month >> structDate.month;
	day >> structDate.day;
	return (structDate);
}

std::map<str, float> csvStrToMap(str src)
{
	std::map<str, float> dataBase;
	bool firstLine = false;
	while (src.find('\n') != std::string::npos)
	{
		if (firstLine == false)
		{
			firstLine = true;
			src.erase(0, src.find('\n') + 1);
			continue;
		}
		str line;
		line = src.substr(0, src.find('\n'));
		str date = src.substr(0, src.find(','));
		line.erase(0, src.find(',') + 1);
		sstr value(line);
		src.erase(0, src.find('\n') + 1);
		if (value.str().find_first_not_of("1234567890.") != str::npos || value.str()[0] == '.')
			throw valueNotANumberException();
		try
		{
			date = parsDate(date);
		}
		catch(const std::exception& e)
		{
			throw dateNotValidException();
		}
		float val;
		value >> val;
		dateToStruct(date);
		dataBase[date] = val;
	}
	return (dataBase);
}

std::map<str, float> inputStrToMap(str src)
{
	std::map<str, float> dataBase;
	bool firstLine = false;
	while (src.find('\n') != std::string::npos)
	{
		if (firstLine == false)
		{
			firstLine = true;
			src.erase(0, src.find('\n') + 1);
			continue;
		}
		str line;
		line = src.substr(0, src.find('\n'));
		char end = '|';

		if (line.find(end) == str::npos) { end = '\n'; }
		str date = src.substr(0, src.find(end));
		while (date[date.size() - 1] == ' ')
			date.erase(date.size() - 1, date.size());
		line.erase(0, src.find(end) + 1);
		while (line[0] == ' ')
			line.erase(0, 1);
		sstr value(line);
		std::cout << "value : '" << value.str() << "'" << std::endl;
		src.erase(0, src.find('\n') + 1);
		float val = 0;
		if ((value.str()[0] != '-' && value.str().find_first_not_of("1234567890.") != str::npos) || value.str()[0] == '.')
			val = 1001;
		else if (value.str() == "")
			val = 1002;
		try
		{
			std::cout << "[" << date << "]" << std::endl;
			date = parsDate(date);
		}
		catch(const std::exception& e)
		{
			throw dateNotValidException();
		}
		if (val <= 1000)
			value >> val;
		dateToStruct(date);
		static str d = "+";
		if (dataBase.find(date) == dataBase.end())
			dataBase[date] = val;
		else
		{
			dataBase[dataBase.find(date)->first + d] = val;
			d += "+";
		}
	}
	return (dataBase);
}