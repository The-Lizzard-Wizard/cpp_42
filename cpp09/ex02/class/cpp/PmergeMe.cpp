#include "../hpp/PmergeMe.hpp"
#include <cstddef>
#include <string>
#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe(char **str_array, int argc)
{
	size_t i = 1;
	while ((int)i <= argc - 1)
	{
		//if (std::string(str_array[i]).find_first_not_of("1234567890") != std::string::npos)
			// error
		t_pair pair;
		int a = std::atoi(str_array[i]);
		int b = 0;
		if ((int)i == argc - 1)
			pair.one = true;
		else
		{
			b = std::atoi(str_array[i + 1]);
			pair.one = false;
		}
		if (pair.one == true)
		{
			pair.b = a;
			pair.s = 0;
			i++;
		}
		else
		{
			pair.b = std::max(a, b);
			pair.s = std::min(a, b);
			i += 2;
		}
		array.push_back(pair);
	}
}

PmergeMe::PmergeMe(PmergeMe &)
{}

//operator =

bool vvpCheckSize(t_vvp &vvp)
{
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	{
		if (it->size() > 1)
			return (false);
	}
	return (true);
}

int sizeVvp(t_vvp &vvp)
{
	int size = 0;
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
		size += it->size();
	return (size);
}

t_vvp splitVvp(t_vvp &vvp)
{
	t_vvp newVvp;
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	{
		if (it->size() == 1)
		{
			newVvp.push_back(*it);
			continue ;
		}
		t_vp part1;
		t_vp part2;
		for (t_vp::iterator pit = it->begin(); pit != (it->begin() + it->size() / 2); pit++)
		{
			part1.push_back(*pit);
		}
		for (t_vp::iterator pit = (it->begin() + it->size() / 2); pit != it->end(); pit++)
		{
			part2.push_back(*pit);
		}
		newVvp.push_back(part1);
		newVvp.push_back(part2);
	}
	return (newVvp);
}

t_vvp mergeBig(t_vvp &vvp)
{
	//display
	std::cout << "\n";
	for (t_vvp::iterator it1 = vvp.begin(); it1 != vvp.end(); it1++)
	{
		std::cout << " [";
		for (std::vector<t_pair>::iterator it = it1->begin(); it != it1->end(); it++)
			std::cout << "(" << it->s << ", " << it->b << ")";
		std::cout << "] ";
	}
	std::cout << "\n";
	t_vvp vvps = splitVvp(vvp);
	if (vvpCheckSize(vvp) == false)
	{
		vvps = mergeBig(vvps); //fuck
	}
	//                   .
	//ca s'est bien :)) /|
	//                 / \ 
	//                  |    |
	//                  |    |
	//                  |    |
	// ça s'est de la merde \ /
	//                      |/
	//                      '
	// for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	// {
	// 	int size = it->size();
	// 	it->clear();
	// 	for (int i = 0; i < size; i++)
	// 	{
	// 		t_pair best = vvps.begin()->back();
	// 		t_vvp::iterator saveIts = vvps.begin();
	// 		for (t_vvp::iterator its = vvps.begin(); its != vvps.end(); its++)
	// 		{
	// 			if (its->begin()->b < best.b)
	// 			{
	// 				best = *its->begin();
	// 				saveIts = its;
	// 			}
	// 		}
	// 		saveIts->erase(saveIts->begin());
	// 		if (saveIts->size() == 0)
	// 			vvps.erase(saveIts);
	// 		it->push_back(best);
	// 	}
	// }
	//display
	std::cout << "\n";
	for (t_vvp::iterator it1 = vvp.begin(); it1 != vvp.end(); it1++)
	{
		std::cout << " [";
		for (std::vector<t_pair>::iterator it = it1->begin(); it != it1->end(); it++)
			std::cout << "(" << it->s << ", " << it->b << ")";
		std::cout << "] ";
	}
	std::cout << "\n";
	return (vvp);
}

void PmergeMe::sort()
{
	for (std::vector<t_pair>::iterator it = array.begin(); it != array.end(); it++)
			std::cout << "(" << it->s << ", " << it->b << ") ";
	std::cout << "<- base input\n";
	t_vvp newVvp;
	newVvp.push_back(array);
	mergeBig(newVvp);
	//mergeBig(newVvp);
}
