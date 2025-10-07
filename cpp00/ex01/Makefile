NAME = PhoneBook
DEPS = PhoneBook.hpp
SRC = main.cpp PhoneBook.cpp
CC = c++ -Wall -Wextra -Werror -g3 -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
