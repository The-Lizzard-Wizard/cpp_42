#include "class/hpp/Bureaucrat.hpp"
#include "class/hpp/Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat solar("solar", 1);
	std::cout << "bureaucrat (" << solar << ") has been created" << std::endl;
	Bureaucrat hollow("hollow", 150);
	std::cout << "bureaucrat (" << hollow << ") has been created" << std::endl;

	std::cout << std::endl;

	Form PraiseTheSun("PraiseTheSun", 1, 1);
	Form LevelUp("LevelUp", 50, 1);

	std::cout << std::endl << "========== sign test ==========" << std::endl;
	solar.signForm(PraiseTheSun);
	
	std::cout << std::endl << "====== double sign test =======" << std::endl;
	
	solar.signForm(PraiseTheSun);
	
	std::cout << std::endl << "=== too low grade test test ===" << std::endl;

	hollow.signForm(LevelUp);

	std::cout << std::endl;
}