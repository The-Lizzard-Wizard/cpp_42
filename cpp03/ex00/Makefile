NAME = Fixed
SRC = main.cpp class/cpp/Fixed.cpp
DEPS =cpp02/ex00/class cpp02/ex00/main.cpp cpp02/ex00/Makefile class/hpp/Fixed.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
