CC			= c++ 
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= ex01

SRC			= main.cpp Bureaucrat.cpp Form.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= Bureaucrat.hpp Form.hpp

all:		$(NAME)

$(NAME):	$(OBJ) 
			$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CC) $(CXXFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re



