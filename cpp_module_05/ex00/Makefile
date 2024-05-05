# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 09:41:03 by fahmadia          #+#    #+#              #
#    Updated: 2024/03/03 09:41:54 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp\
	Bureaucrat.cpp\
	
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
NAME =  bureaucrat
CPP = c++
FLAGS = -c -g -Wall -Wextra -Werror -std=c++98

HEADERS = Bureaucrat.hpp\

all: $(NAME)

$(NAME): $(OBJS) Makefile $(HEADERS)
	$(CPP) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	mkdir -p $(OBJS_DIR)
	$(CPP) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
