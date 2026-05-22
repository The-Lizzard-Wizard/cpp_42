#include "easyfind.tpp"
#include <set>
#include <vector>
#include <iostream>

int main()
{
	std::set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(5);
	set.insert(6);
	set.insert(8);

	try
	{
		std::cout << easyfind(set, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyfind(set, 4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(8);

	try
	{
		std::cout << easyfind(vec, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyfind(vec, 4) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}