#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(Brain &src);
		Brain &operator=(Brain &src);
		~Brain();

		void addIdea(std::string idea, int i);
		void rmIdea(int i);
		std::string getIdea(int i);
		int getNbIdeas();
		void printIdeas();
	private:
		std::string ideas[100];
};

#endif //BRAIN_HPP