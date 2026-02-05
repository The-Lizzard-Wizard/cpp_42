NAME = Animal
SRC = main.cpp class/cpp/Animal.cpp class/cpp/Cat.cpp class/cpp/Dog.cpp class/cpp/WrongAnimal.cpp class/cpp/WrongCat.cpp
DEPS = class/hpp/Animal.hpp class/hpp/Cat.hpp class/hpp/Dog.hpp class/hpp/WrongAnimal.hpp class/hpp/WrongCat.hpp
CC = c++ -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): Makefile $(DEPS) $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
