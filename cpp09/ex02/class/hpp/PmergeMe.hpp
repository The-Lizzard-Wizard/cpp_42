#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

typedef struct s_pair
{
	bool one;
	int b;
	int s;
} t_pair;

typedef std::vector<std::vector<t_pair> > t_vvp;
typedef std::vector<t_pair> t_vp;


class PmergeMe
{
	public:
		PmergeMe(char **str_array, int argc);
		PmergeMe(PmergeMe &src);
		//operator =

		void sort();
	private:
		std::vector<t_pair> array;
};

#endif // PMERGEME_HPP