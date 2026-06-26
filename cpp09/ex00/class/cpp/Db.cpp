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