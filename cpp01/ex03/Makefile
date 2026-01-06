NAME = Unnecessary_violence
SRC = main.cpp class/cpp/HumanA.cpp class/cpp/HumanB.cpp class/cpp/Weapon.cpp
DEPS = class/hpp/HumanA.hpp class/hpp/HumanB.hpp class/hpp/Weapon.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
