NAME = Identify
SRC = main.cpp class/cpp/Base.cpp
DEPS = class/hpp/Base.hpp class/hpp/A.hpp class/hpp/B.hpp class/hpp/C.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
