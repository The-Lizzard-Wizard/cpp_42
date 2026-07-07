#include <stack>
#include <string>
#include <iostream>

typedef std::string str;

void parsInput(std::stack<char> &input, str args)
{
	while (args.find(' ') != std::string::npos)
	{
		str part = args.substr(0, args.find(' '));
		if (part.size() == 1)
			input.push(part[0]);
		else
		{} // error
		args.erase(0, args.find(' ') + 1);
	}
	if (args.size() > 0)
		input.push(args[0]);
}

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

int charToInt(char c)
{
	if (isNum(c))
		return (c - 48);
	return (0);
}

int resolve(std::stack<char> &input)
{
	int res = 0;
	int a = 0;
	int b = 0;
	if (input.top() == '+')
	{
		input.pop();
		if (isOp(input.top()))
			a = resolve(input);
		else if (isNum(input.top()))
			a = charToInt(input.top());
		else
		{} // error
		input.pop();
		if (isOp(input.top()))
			b = resolve(input);
		else if (isNum(input.top()))
			b = charToInt(input.top());
		else
		{} // error
		input.pop();
		res = b + a;
	}
	else if (input.top() == '-')
	{
		input.pop();
		if (isOp(input.top()))
			a = resolve(input);
		else if (isNum(input.top()))
			a = charToInt(input.top());
		else
		{} // error
		input.pop();
		if (isOp(input.top()))
			b = resolve(input);
		else if (isNum(input.top()))
			b = charToInt(input.top());
		else
		{} // error
		input.pop();
		res = b - a;
	}
	else if (input.top() == '*')
	{
		input.pop();
		if (isOp(input.top()))
			a = resolve(input);
		else if (isNum(input.top()))
			a = charToInt(input.top());
		else
		{} // error
		input.pop();
		if (isOp(input.top()))
			b = resolve(input);
		else if (isNum(input.top()))
			b = charToInt(input.top());
		else
		{} // error
		input.pop();
		res = b * a;
	}
	else if (input.top() == '/')
	{
		input.pop();
		if (isOp(input.top()))
			a = resolve(input);
		else if (isNum(input.top()))
			a = charToInt(input.top());
		else
		{} // error
		input.pop();
		if (isOp(input.top()))
			b = resolve(input);
		else if (isNum(input.top()))
			b = charToInt(input.top());
		else
		{} // error
		input.pop();
		res = b / a;
	}
	return (res);
}

int main(int argc, char **argv)
{
	int res = 0;
	std::stack<char> input;
	if (argc == 1)
		return (1);
	parsInput(input, argv[1]);
	// while(!input.empty()) {
	// 	std::cout << input.top() << "\n";
	// 	input.pop();
	// }
	//add error handling
	res = resolve(input);
	std::cout << res << std::endl;
	return (0);
}