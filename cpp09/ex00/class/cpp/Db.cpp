#include "../hpp/Db.hpp"
#include "../../utils.hpp"
#include <iostream>

Db::Db()
{}

Db::Db(str DbTxt)
{
	init_date(date);
	try
	{
		dataBase = csvStrToMap(DbTxt);
	}
	catch(const std::exception& e) {}
	DbStr = DbTxt;
}

Db::Db(const Db &src)
{
	init_date(date);
	try
	{
		dataBase = inputStrToMap(src.getStr());
	}
	catch(const std::exception& e) {}
}

// Db &Db::operator=(Db &)
// {}

str Db::getStr() const
{
	return (DbStr);
}

int displayData(str date, str key, float mult, std::map<str, float> dataBase)
{
	if (mult == 1001)
	{
		std::cout << "Error: value is not a number." << std::endl;
		return (0) ;
	}
	else if (mult == 1002)
	{
		std::cout << "Error: value not registered." << std::endl;
		return (0) ;
	}
	else if (mult == 1003)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (0) ;
	}
	else if (mult < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0) ;
	}
	std::cout << date.substr(0, 4) << "-" << date.substr(4, 2) << "-" << date.substr(6, 2);
	std::cout << " => " << mult << " = " << dataBase[key.substr(0, 8)] * mult << std::endl;
	return (1) ;
}

void Db::outFormInput(Input &Input)
{
	std::map<str, float> inMap = Input.getMap();
	for (std::map<str, float>::iterator i = inMap.begin(); i != inMap.end(); i++)
	{
		if (!validDate(i->first, date) || i->first.substr(0, 8).size() != 8)
		{
			std::cout << "Error: bad input => " << i->first << std::endl;
			continue ;
		}
		if (dataBase.find(i->first.substr(0, 8)) != dataBase.end())
		{
			if (!displayData(i->first, i->first, i->second, dataBase))
				continue ;
		}
		else
		{
			std::map<str, float>::iterator it = dataBase.lower_bound(i->first);

			if (it == dataBase.begin())
				throw std::runtime_error("Error : no earlier date.");

			--it;
			if (!displayData(i->first, it->first, i->second, dataBase))
				continue ;
		}
	}
}