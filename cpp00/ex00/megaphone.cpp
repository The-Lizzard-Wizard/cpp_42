#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
	size_t j = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		std::exit(0);
	}
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char) std::toupper(argv[i][j]);
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}
