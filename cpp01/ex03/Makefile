CC			= c++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= unnecessary_violence

SRC			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= Weapon.hpp HumanA.hpp HumanB.hpp

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



