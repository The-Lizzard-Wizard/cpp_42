#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string	file_content("");
	if (argc != 4)
	{
		std::cout << "try ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return (2);
	}
	std::string to_replace(argv[1]);
	std::string replacer(argv[2]);
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		size_t pos = 0;
		std::string s("");
		while (getline(file, s))
		{
			while ((pos = s.find(to_replace, pos)) != std::string::npos)
			{
				s = s.substr(0, pos) + replacer + s.substr(pos + to_replace.length());
				pos += replacer.length();
			}
			file_content = file_content + s + "\n";
		}
		std::cout << file_content << std::endl;
	}
	else
	{
		std::cout << "<" << argv[1] << ">" << " is a not valid file" << std::endl;
		return (1);
	}
	file.close();
	return (0);
}