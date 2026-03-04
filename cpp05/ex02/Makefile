NAME = Bureaucrat
SRC = \
	main.cpp \
	class/cpp/Bureaucrat.cpp \
	class/cpp/AForm.cpp \
	class/cpp/ShrubberyCreationForm.cpp \
	class/cpp/RobotomyRequestForm.cpp \
	class/cpp/PresidentialPardonForm.cpp
DEPS = \
	class/hpp/Bureaucrat.hpp \
	class/hpp/AForm.hpp \
	class/hpp/ShrubberyCreationForm.hpp \
	class/hpp/RobotomyRequestForm.hpp \
	class/hpp/PresidentialPardonForm.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
