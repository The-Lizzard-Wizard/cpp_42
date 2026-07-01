#include "../hpp/Db.hpp"
#include "../../utils.hpp"
#include <iostream>

Db::Db()
{}

Db::Db(str DbTxt)
{
	try
	{
		dataBase = csvStrToMap(DbTxt);
	}
	catch(const std::exception& e) {}
	DbStr = DbTxt;
}

Db::Db(const Db &src)
{
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

void Db::outFormInput(Input &Input)
{
	std::map<str, float> inMap = Input.getMap();
	for (std::map<str, float>::iterator i = inMap.begin(); i != inMap.end(); i++)
	{
		if (dataBase.find(i->first.substr(0, 8)) != dataBase.end())
		{
			if (i->second == 1001)
				//fait un truc
			else if (i->second == 1002)
				//fait un autre truc
			std::cout << i->first.substr(0, 4) << "-" << i->first.substr(4, 2) << "-" << i->first.substr(6, 2);
			std::cout << " => " << i->second << " = " << dataBase[i->first.substr(0, 8)] * i->second << std::endl;
		}
		else
		{}
			//trouve la date la plus proche
	}
}