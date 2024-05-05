# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 11:40:09 by fahmadia          #+#    #+#              #
#    Updated: 2024/04/02 14:54:43 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp 
	
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
NAME = easyfind
CPP = c++
FLAGS = -c -g -Wall -Wextra -Werror -std=c++98

HEADERS = easyfind.hpp easyfind.tpp

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
