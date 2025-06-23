CC			= c++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= phonebook

SRC			= main.cpp PhoneBook.cpp Contact.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= PhoneBook.hpp Contact.hpp

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADERS)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re



