NAME = BSP
SRC = main.cpp class/cpp/Fixed.cpp class/cpp/Point.cpp bsp.cpp
DEPS = class/hpp/Fixed.hpp class/hpp/Point.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
