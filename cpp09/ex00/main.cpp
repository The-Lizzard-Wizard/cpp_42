#include "utils.hpp"
#include "class/hpp/Db.hpp"
#include <iostream>
#include "class/hpp/Input.hpp"

int main(int argc, char **argv)
{
	str DbTxt;
	str InputTxt;
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		DbTxt = fileToStr("data.csv");
		InputTxt = fileToStr(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Db db(DbTxt);
	Input input(InputTxt);
	db.outFormInput(input);
	return (0);
}