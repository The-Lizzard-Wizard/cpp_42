#include <stack>
#include <string>
#include <iostream>
#include "excep.hpp"

typedef std::string str;

float resolve(std::stack<char> &input);

bool isOp(char c)
{
	if (c == '+' || c == '-' || c =='/' || c == '*')
		return (true);
	return (false);
}

bool isNum(char c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

float charToInt(char c)
{
	if (isNum(c))
		return (c - 48);
	return (0);
}

void parsInput(std::stack<char> &input, str args)
{
	int op = 0;
	int num = 0;
	while (args.size() > 0)
	{
		str part;
		if (args.find(' ') != str::npos)
			part = args.substr(0, args.find(' '));
		else
			part = args.substr(0, args.find('\0'));
		if (part.size() == 1)
		{
			input.push(part[0]);
		}
		else
		{
			throw notValidInput();
		}
		if (isNum(part[0]))
			num++;
		if (isOp(part[0]))
			op++;
		if (args.find(' ') != str::npos)
			args.erase(0, args.find(' ') + 1);
		else
			args.erase(0, args.find('\0'));
		
	}
	if (num != op + 1)
	{
		throw notValidInput();
	}
}

float getAB(std::stack<char> &input)
{
	float res = 0;
	if (isOp(input.top()))
		res = resolve(input);
	else if (isNum(input.top()))
	{
		res = charToInt(input.top());
		input.pop();
	}
	else
	{
		throw notValidInput();
	}
	return (res);
}

float resolve(std::stack<char> &input)
{
	float res = 0;
	float a = 0;
	float b = 0;

	char op = input.top();
	input.pop();

	try
	{
		a = getAB(input);
		b = getAB(input);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	


	if (op == '+')
		res = b + a;
	else if (op == '-')
		res = b - a;
	else if (op == '*')
		res = b * a;
	else if (op == '/')
		res = b / a;
	return (res);
}

int main(int argc, char **argv)
{
	int res = 0;
	std::stack<char> input;
	if (argc == 1)
		return (1);
	try
	{
		parsInput(input, argv[1]);
		res = resolve(input);
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}