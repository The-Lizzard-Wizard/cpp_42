NAME = Bureaucrat
SRC = main.cpp class/cpp/Bureaucrat.cpp class/cpp/AForm.cpp
DEPS = class/hpp/Bureaucrat.hpp class/hpp/AForm.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
