CC			= c++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= phonebook

SRC			= main.cpp PhoneBook.cpp Contact.cpp contact_utils.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= PhoneBook.hpp Contact.hpp

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



