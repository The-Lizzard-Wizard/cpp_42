NAME = ZombieHorde
SRC = main.cpp class/cpp/Zombie.cpp zombieHorde.cpp
DEPS = Zombie.h class/hpp/Zombie.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
