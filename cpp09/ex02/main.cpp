#include "class/hpp/PmergeMe.hpp"
#include <iostream>
#include <sstream>

void is_sorted(t_vvp vvp)
{
	std::stringstream sstr;
	bool sorted = true;
	int pre = -1;
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	{

		if (it->back().b < pre)
		{
			sorted = false;
			sstr << "\e[0;31m";
		}
		pre = it->back().b;
		sstr << it->back().b << " ";
		sstr << "\e[0m";
	}
	if (sorted)
		std::cout << "sorted" << std::endl;
	else
	{
		std::cout << "unsorted" << std::endl;
		std::cout << sstr.str() << std::endl;
	}
}

int main(int argc, char **argv)
{
	PmergeMe pmm(argv, argc);
	t_vvp sa = sort(pmm.get_array(), 1);
	is_sorted(sa);
	displayVvp(sa);
}