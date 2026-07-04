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

void init_date(std::map<int, int> &date)
{
	date[1] = 31;
	date[2] = 28;
	date[3] = 31;
	date[4] = 30;
	date[5] = 31;
	date[6] = 30;
	date[7] = 31;
	date[8] = 31;
	date[9] = 30;
	date[10] = 31;
	date[11] = 30;
	date[12] = 31;
}

bool validDate(str date, std::map<int, int> dateMap)
{
	sstr sy(date.substr(0, 4));
	sstr sm(date.substr(4, 2));
	sstr sd(date.substr(6, 2));
	int year;
	int month;
	int day;
	sy >> year;
	sm >> month;
	sd >> day;
	bool bi = false;
	if (year % 4 == 0)
		bi = true;
	else if (year % 100 == 0)
		bi = false;
	else if (year % 400 == 0)
		bi = true;
	else
		bi = false;
	if (dateMap.find(month) != dateMap.end())
	{
		if (bi == true)
			date[2] = 29;
		if (day <= 0 || day > dateMap[month])
			return (false);
	}
	else
		return (false);
	return (true);
}

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

str parsDate(str rawDate, int)
{
	str olddate = rawDate;
	str year(rawDate.substr(0, rawDate.find('-')));
	rawDate.erase(0, rawDate.find('-') + 1);
	str month(rawDate.substr(0, rawDate.find('-')));
	rawDate.erase(0, rawDate.find('-') + 1);
	str day(rawDate);
	if (year.find_first_not_of("1234567890") != str::npos)
		return (olddate);
	if (month.find_first_not_of("1234567890") != str::npos)
		return (olddate);
	if (day.find_first_not_of("1234567890") != str::npos)
		return (olddate);
	
	if (olddate.size() != 10)
		return (olddate);

	std::map<int, int> date;
	init_date(date);
	if (!validDate(year + month + day, date))
		return (olddate);
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
		src.erase(0, src.find('\n') + 1);
		float val = 0;
		if ((value.str()[0] != '-' && value.str().find_first_not_of("1234567890.") != str::npos) || value.str()[0] == '.')
			val = 1001;
		else if (value.str() == "")
			val = 1002;
		date = parsDate(date, 1);
		if (val <= 1000)
		{
			value >> val;
			if (val > 1000)
				val = 1003;
		}
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