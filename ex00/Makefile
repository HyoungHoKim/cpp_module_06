CPP = clang++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 

SRCS = Converter.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = convert

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
		
.PHONY: all clean fclean re test
