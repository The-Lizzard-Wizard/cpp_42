#include "class/hpp/PmergeMe.hpp"

//todo:
//[ ] vvpToVp -> fonction qui recree un vetor de pair a partir d'un vector de vector de pair
//[ ] SplitVvp -> fonction qui split un vector de pair et le sort en output et qui prand c'est parametre -> (vector de pair, numbre de split)
//[ ] sortVpByBig -> fonction qui tri un vector de pair a partir du plus grand dans la pair et en renvoi une copy
//[ ] mergeBig -> fonction qui s'appelle recursivecment tamp que les split du vector de pair cree avec vpTpVvp n'on pas une tous un taile de 1
//				et tri chacun des split aprais l'appelle recursif de mergeBig
//[ ] insertSmall -> fonction qui insert-sort les petit numbre des pair a partire de la position es leur grand dans le vector de pair

//cree un vetor de pair [a1b1,a2b2,etc]
//dans le sort
//call la fonction mergeBig
//call la fonction insertSmall

//                 [1, 6] [3, 10]  [5, 22]  [4, 5]  [40, 50]  [2, 3]  [3, 6]  [3, 5]

//                ([1, 6] [3, 10] [5, 22] [4, 5])    ([40, 50] [2, 3] [3, 6] [3, 5])

//           ([1, 6] [3, 10])    ([5, 22] [4, 5])    ([40, 50] [2, 3])    ([3, 6] [3, 5])

// ([1, 6])    ([3, 10])    ([5, 22])    ([4, 5])    ([40, 50])    ([2, 3])    ([3, 6])    ([3, 5])

//           ([1, 6] [3, 10])    ([4, 5] [5, 22])    ([2, 3]s[40, 50])    ([3, 5]s[3, 6])

//                ([1, 6] [4, 5] [3, 10] [5, 22])    ([2, 3] [3, 5] [3, 6] [40, 50])

//                     [2, 3] [3, 5] [4, 5] [1, 6]  [3, 6] [3, 10] [5, 22] [40, 50]

int main(int argc, char **argv)
{
	PmergeMe pmm(argv, argc);
	t_vvp sa = sort(pmm.get_array());
}