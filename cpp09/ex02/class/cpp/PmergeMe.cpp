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
		pair.one = false;
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
	return (group);
}

void displayVvp(t_vvp &vvp)
{
	std::cout << "\n";
	for (t_vvp::iterator it1 = vvp.begin(); it1 != vvp.end(); it1++)
	{
		std::cout << " [";
		for (std::vector<t_pair>::iterator it = it1->begin(); it != it1->end(); it++)
		{
			if (it->one == false)
				std::cout << "(" << it->s << ", " << it->b << ")";
			else
				std::cout << "(" << it->b << ")";
		}
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

t_vvp insert_sort(t_vvp insert_array)
{
	std::cout << "====================insert====================" << std::endl;
	std::cout << "unsorted : ";
	displayVvp(insert_array);

	t_vvp sorted;
	t_vvp main;
	t_vvp pend;
	t_vvp non_part;
	int size;
	bool first_one = false;
	if (insert_array.size() > 0)
	{
		size = insert_array.begin()->size();
		first_one = insert_array.begin()->begin()->one;
	}
	else
	{
		size = 0;
		first_one = false;
	}
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
			if ((int)it->size() != size || (first_one == false && it->begin()->one == true))
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
	int jacob_index = 0;
	while ((insert_index) < (int)pend.size())
	{
		t_vvp::iterator it = pend.begin() + (jacob(jacob_index) - 1);
		if ((jacob(jacob_index) - 1) >= (int)pend.size())
			it = pend.end() - 1;
		for (;it >= pend.begin() + insert_index;
		it--)
		{
			//binary search
			displayVvp(main);
			// int high = std::pow(2, jacob_index + 1) - 1;
			// int low = 0;
			// int mid = low + (high - low) / 2;
			// if (high >= (int)main.size())
			// 	high = main.size() - 1;
			// while (low <= high)
			// {
			// 	mid = low + (high - low) / 2;
			// 	std::cout << "range : " << high << " jacob : " << jacob(jacob_index) << " jacob index : " << jacob_index << " to insert : " << it->back().b << " low : " << low << " high : " << high << " mid : " << mid << " at low : " << main[low].back().b << " at high : " << main[high].back().b << " at mid : " << main[mid].back().b << std::endl;
			// 	if (main[mid].back().b == it->back().b)
			// 		break;
			// 	if (main[mid].back().b < it->back().b)
			// 		low = mid + 1;
			// 	if (main[mid].back().b > it->back().b)
			// 		high = mid - 1;
			// }
			// if (main[low].back().b <= it->back().b)
			// {
			// 	std::cout << "insert " << it->back().b << " at right of " << main[mid].back().b << " mid is " << mid << std::endl;
			// 	main.insert(main.begin() + (low + 1), *it);
			// }
			// if (main[low].back().b > it->back().b)
			// {
			// 	std::cout << "insert " << it->back().b << " at left of " << main[mid].back().b << " mid is " << mid << std::endl;
			// 	main.insert(main.begin() + low, *it);
			// }

			int low = 0;
			int high = pow(2, jacob_index + 1) - 1;
			if (high > (int)main.size())
				high = (int)main.size() - 1;

			while (low <= high)
			{
				int mid = low + (high - low) / 2;

				if (mid >= (int)main.size())
				{
					low = mid;
					break ;
				}
				if (main[mid].back().b < it->back().b)
					low = mid + 1;
				else
					high = mid - 1;
			}
			std::cout << low << std::endl;
			if (low >= (int)main.size())
				low = main.size() - 1;
			std::cout << low << std::endl;
			if (main[low].back().b < it->back().b)
			{
				std::cout << "insert " << it->back().b << " at right of " << main[low].back().b << " mid is " << low << std::endl;
				main.insert(main.begin() + (low + 1), *it);
			}
			if (main[low].back().b >= it->back().b)
			{ 
				std::cout << "insert " << it->back().b << " at left of " << main[low].back().b << " mid is " << low << std::endl;
				main.insert(main.begin() + low, *it);
			}
			//main.insert(main.begin() + low, *it);

			std::cout << "main at the insertion step : ";
			displayVvp(main);
			std::cout << "index " << insert_index << " pend at the insertion step : ";
			displayVvp(pend);
		}
		insert_index = (jacob(jacob_index));
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

	return(main);
}

t_vvp convert_to_simple_num(t_vvp array)
{
	t_vvp new_array;

	for (t_vvp::iterator it = array.begin(); it != array.end(); it++)
	{
		if (it->back().one == false)
		{
			t_vp vp1;
			t_pair p1;
			p1.b = it->back().s;
			p1.s = 0;
			p1.one = true;
			vp1.push_back(p1);

			t_vp vp2;
			t_pair p2;
			p2.b = it->back().b;
			p2.s = 0;
			p2.one = true;
			vp2.push_back(p2);

			new_array.push_back(vp1);
			new_array.push_back(vp2);
		}
		else
		{
			t_vp vp2;
			t_pair p2;
			p2.b = it->back().b;
			p2.s = 0;
			p2.one = true;
			vp2.push_back(p2);

			new_array.push_back(vp2);
		}
	}

	return (new_array);
}

t_vvp sort(t_vvp array, int index)
{
	displayVvp(array);
	t_vvp newArray;
	t_vvp insert_array;
	if (array.size() != 2 && vvpCheckSize(array))
	{
		for (int i = 0; i < (int)array.size(); i++)
		{
			if (array.size() >= 2 && (array[i].size() == array[i + 1].size() && array[i + 1].begin()->one == false))
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
		insert_array = sort(newArray, index + 1);
		insert_array = splitVvp(insert_array);
	}
	else
	{
		insert_array = array;
		insert_array = splitVvp(insert_array);
	}
	//insertion
	t_vvp main;
	if (index != 1)
		main = insert_sort(insert_array);
	else
	{
		t_vvp s_n_array = convert_to_simple_num(insert_array);
		displayVvp(s_n_array);
		main = insert_sort(s_n_array);
	}
	return (main);
}
