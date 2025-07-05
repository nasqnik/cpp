CC			= c++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= bsp

SRC			= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= Fixed.hpp Point.hpp

all:		$(NAME)

$(NAME):	$(OBJ) 
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re



