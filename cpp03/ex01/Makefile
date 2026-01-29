NAME = ScavTrap
SRC = main.cpp class/cpp/ClapTrap.cpp class/cpp/ScavTrap.cpp
DEPS = class/hpp/ClapTrap.hpp class/hpp/ScavTrap.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
