NAME = RPN
SRC = main.cpp excep.cpp
DEPS = excep.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98 -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
