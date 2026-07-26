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
	else
		return (vvps);
	//    .
	//   /|
	//  / |                  ça s'est de la merde
	//   |                     |
	//   |                     |
	//   |                     |
	// ça s'est bien :))      \ /
	//                        |/
	//                        '
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	{
		int size = it->size();
		it->clear();
		if (size == 1)
		{
			it->push_back(*vvps.begin()->begin());
			vvps.erase(vvps.begin());
		}
		else
		{
			t_vvp::iterator itPart1 = vvps.begin();
			t_vvp::iterator itPart2 = vvps.begin()++;
			for (int i = 0; i < size; i++)
			{
				itPart1 = vvps.begin();
				itPart2 = itPart1++;
				if (itPart1->size() > 0 && itPart2->size() > 0)
				{
					if (itPart1->begin()->b < itPart2->begin()->b)
					{
						it->push_back(*itPart1->begin());
						itPart1->erase(itPart1->begin());
					}
					else
					{
						it->push_back(*itPart2->begin());
						itPart2->erase(itPart2->begin());
					}
				}
				else if (itPart1->size() > 0)
				{
					it->push_back(*itPart1->begin());
					itPart1->erase(itPart1->begin());
				}
				else if (itPart2->size() > 0)
				{
					it->push_back(*itPart2->begin());
					itPart2->erase(itPart2->begin());
				}
			}
			vvps.erase(vvps.begin());
			vvps.erase(vvps.begin());
		}
	}
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
