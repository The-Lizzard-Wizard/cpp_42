NAME = btc
SRC = main.cpp utils.cpp class/cpp/Input.cpp class/cpp/Db.cpp
DEPS = utils.hpp class/hpp/Input.hpp class/hpp/Db.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
