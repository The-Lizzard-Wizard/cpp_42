#include "../hpp/Btc.hpp"
#include "../../utils.hpp"

Btc::Btc()
{}

Btc::Btc(str DbTxt)
{
	try
	{
		input = csvStrToMap(DbTxt);
	}
	catch(const std::exception& e) {}
	DbStr = DbTxt;
}

Btc::Btc(const Btc &src)
{
	try
	{
		input = csvStrToMap(src.getStr());
	}
	catch(const std::exception& e) {}
}

// Btc &Btc::operator=(Btc &)
// {}

str Btc::getStr() const
{
	return (DbStr);
}