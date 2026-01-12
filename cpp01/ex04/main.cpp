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
	std::string to_replace(argv[2]);
	std::string replacer(argv[3]);
	std::string		file_name(argv[1]);
	file_name += ".replace";
	std::ofstream out_file(file_name.c_str());
	if (!out_file.is_open())
		return (1);
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		std::string s("");
		while (getline(file, s))
		{
			size_t pos = 0;
			while ((pos = s.find(to_replace, pos)) != std::string::npos)
			{
				s = s.substr(0, pos) + replacer + s.substr(pos + to_replace.length());
				pos += replacer.length();
			}
			out_file << s;
			if (!file.eof())
				out_file << std::endl;
		}
	}
	else
	{
		out_file.close();
		std::cout << "<" << argv[1] << ">" << " is a not valid file" << std::endl;
		return (1);
	}
	out_file.close();
	file.close();
	return (0);
}