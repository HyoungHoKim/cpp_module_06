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
	./$(NAME) 42.0f
	./$(NAME) 12341234.12341234f
	./$(NAME) -12341234.12341234f
	./$(NAME) -inff
	./$(NAME) +inff
	./$(NAME) nanf
	./$(NAME) nan
	./$(NAME) inf
	./$(NAME) -inf
	./$(NAME)  1.79770e+308
		
.PHONY: all clean fclean re test
