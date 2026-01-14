CXX			= c++ 
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

NAME		= ex02

SRC			= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJ			= $(SRC:%.cpp=%.o)
HEADERS		= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp

all:		$(NAME)

$(NAME):	$(OBJ) 
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re



