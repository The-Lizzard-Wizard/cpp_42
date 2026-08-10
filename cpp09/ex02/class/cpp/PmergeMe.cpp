#include "../hpp/PmergeMe.hpp"
#include <cstddef>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

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
		t_vp vp;
		vp.push_back(pair);
		array.push_back(vp);
	}
}

PmergeMe::PmergeMe(PmergeMe &)
{}

//operator =

t_vvp PmergeMe::get_array() { return (array); }

bool vvpCheckSize(t_vvp vvp)
{
	if (vvp.size() == 1)
		return (false);
	else if (vvp.size() > 1 && vvp[0].size() != vvp[1].size())
		return (false);
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
	if (vvp.size() == 0)
		return vvp;
	int size = vvp.begin()->size();
	t_vvp newVvp;
	for (t_vvp::iterator it = vvp.begin(); it != vvp.end(); it++)
	{
		if (it->size() == 1 || size != (int)it->size())
		{
			newVvp.push_back(*it);
			continue ;
		}
		size = it->size();
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

t_vp groupVp(t_vp part1, t_vp part2)
{
	t_vp group;
	if (part1.back().b > part2.back().b)
	{
		for (int i = 0; i < (int)part2.size(); i++)
			group.push_back(part2[i]);
		for (int i = 0; i < (int)part1.size(); i++)
			group.push_back(part1[i]);
	}
	else
	{
		for (int i = 0; i < (int)part1.size(); i++)
			group.push_back(part1[i]);
		for (int i = 0; i < (int)part2.size(); i++)
			group.push_back(part2[i]);
	}
	// std::cout << "group function p1 : ";
	// for (std::vector<t_pair>::iterator it = part1.begin(); it != part1.end(); it++)
	// 		std::cout << "(" << it->s << ", " << it->b << ")";
	// std::cout << std::endl;
	// std::cout << "group function p2 : ";
	// for (std::vector<t_pair>::iterator it = part2.begin(); it != part2.end(); it++)
	// 		std::cout << "(" << it->s << ", " << it->b << ")";
	// std::cout << std::endl;
	// std::cout << "group function output : ";
	// for (std::vector<t_pair>::iterator it = group.begin(); it != group.end(); it++)
	// 		std::cout << "(" << it->s << ", " << it->b << ")";
	// std::cout << std::endl;
	return (group);
}

void displayVvp(t_vvp &vvp)
{
	std::cout << "\n";
	for (t_vvp::iterator it1 = vvp.begin(); it1 != vvp.end(); it1++)
	{
		std::cout << " [";
		for (std::vector<t_pair>::iterator it = it1->begin(); it != it1->end(); it++)
			std::cout << "(" << it->s << ", " << it->b << ")";
		std::cout << "] ";
	}
	std::cout << "\n";
}

int jacob(int index)
{
	int a = 1;
	int b = 3;
	if (index == 0)
		return (a);
	else if (index == 1)
		return (b);
	else
	{
		for (int i = 1; i < index; i++)
		{
			int tmp = b;
			b = b + (a * 2);
			a = tmp;
		}
	}
	return (b);
}

t_vvp sort(t_vvp array)
{
	displayVvp(array);
	t_vvp newArray;
	t_vvp insert_array;
	if (vvpCheckSize(array))
	{
		for (int i = 0; i < (int)array.size(); i++)
		{
			if (array.size() >= 2 && array[i].size() == array[i + 1].size())
			{
				t_vp p1 = array[i];
				t_vp p2 = array[i + 1];
				t_vp group = groupVp(p1, p2);
				array.erase(array.begin());
				array.erase(array.begin());
				i = -1;
				newArray.push_back(group);
			}
			else
			{
				newArray.push_back(array[i]);
				array.erase(array.begin());
				i = -1;
			}
		}
		insert_array = sort(newArray);
		insert_array = splitVvp(insert_array);
	}
	else
	{
		insert_array = array;
		insert_array = splitVvp(insert_array);
	}
	//insertion
	std::cout << "====================insert====================" << std::endl;
	std::cout << "unsorted : ";
	displayVvp(insert_array);
	//TMP ================================
	t_vvp cpy = insert_array;

	t_vvp sorted;
	t_vvp main;
	t_vvp pend;
	t_vvp non_part;
	int size;
	if (insert_array.size() > 0)
		size = insert_array.begin()->size();
	else
		size = 0;
	int mod = 0;
	bool non_part_bool = false;
	//init main and pend
	if (insert_array.size() > 1)
	{
		main.push_back(insert_array.front());
		insert_array.erase(insert_array.begin());
		main.push_back(insert_array.front());
		insert_array.erase(insert_array.begin());
		for (t_vvp::iterator it = insert_array.begin(); it != insert_array.end(); it++)
		{
			mod++;
			if ((int)it->size() != size)
				non_part_bool = true;
			if (non_part_bool == false)
			{
				if (mod % 2 == 1)
					pend.push_back(*it);
				else
					main.push_back(*it);
			}
			else
				non_part.push_back(*it);
			size = it->size();
		}
	}
	std::cout << " pend : ";
	displayVvp(pend);
	std::cout << " non part : ";
	displayVvp(non_part);
	std::cout << " main : ";
	displayVvp(main);

	//binary insertion sort here=========

	int insert_index = 0;
	int jacob_index = 1;
	while (insert_index < (int)pend.size())
	{
		//CA CA MARCH PAS==== (le for)
		for (t_vvp::iterator it = pend.begin() + insert_index; it != (pend.begin() + insert_index + (jacob(jacob_index) - 1)); it++)
		{
			//binary search
			std::cout << ":))\n";
			displayVvp(main);
			int high = std::pow(2, jacob_index + 1) - 1;
			int low = 0;
			int mid = low + (high - low) / 2;
			while (low <= high)
			{
				mid = low + (high - low) / 2;
				std::cout << "jacob : " << jacob(jacob_index) << "jacob index : " << jacob_index << " to insert : " << it->back().b << " low : " << low << " high : " << high << " mid : " << mid << std::endl;
				if (main[mid].back().b < it->back().b)
					low = mid + 1;
				if (main[mid].back().b > it->back().b)
					high = mid - 1;
			}
			if (main[mid].back().b < it->back().b)
				main.insert(main.begin() + (mid + 1), *it);
			if (main[mid].back().b > it->back().b)
				main.insert(main.begin() + mid, *it);
			std::cout << "main at the insertion step : ";
			displayVvp(main);
		}
		insert_index = (jacob(jacob_index) - 1);
		jacob_index++;
	}

	//===================================

	//insert non part to main
	for (t_vvp::iterator it = non_part.begin(); it != non_part.end(); it++)
	{
		main.push_back(*it);
	}

	std::cout << " sorted : \n";
	displayVvp(main);
	std::cout << "==============================================" << std::endl;

	//change cpy to main
	return(main);
}
