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

#ifndef DEBUG
# define DEBUG true
#endif //DEBUG

class PmergeMe
{
	public:
		PmergeMe(char **str_array, int argc);
		PmergeMe(PmergeMe &src);
		//operator =

		t_vvp get_array();
	private:
		t_vvp array;
};

t_vvp sort(t_vvp array, int index);
void displayVvp(t_vvp &vvp);

#endif // PMERGEME_HPP