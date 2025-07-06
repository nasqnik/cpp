CC			= c++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= ClapTrap1

SRC			= main.cpp ClapTrap.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= ClapTrap.hpp

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



