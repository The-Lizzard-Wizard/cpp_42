#include "../hpp/Input.hpp"
#include "../../utils.hpp"
#include <iostream>

Input::Input()
{}

Input::Input(str DbTxt)
{
	try
	{
		input = inputStrToMap(DbTxt);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	DbStr = DbTxt;
	for (std::map<str, float>::iterator i = input.begin(); i != input.end(); i++)
	{
		std::cout << i->first << " | " << i->second << std::endl;
	}

}

Input::Input(const Input &src)
{
	try
	{
		input = inputStrToMap(src.getStr());
	}
	catch(const std::exception& e) {}
}

// Input &Input::operator=(Input &)
// {}

str Input::getStr() const
{
	return (DbStr);
}

std::map<str, float> Input::getMap() const
{
	return (input);
}