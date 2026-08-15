#include "class/hpp/PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pmm(argv, argc);
	t_vvp sa = sort(pmm.get_array(), 1);
}