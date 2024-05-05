# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:08:54 by fahmadia          #+#    #+#              #
#    Updated: 2024/01/18 20:10:16 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp\
	
OBJS = $(SRCS:%.cpp=%.o)
NAME = brain
CPP = c++
FLAGS = -c -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CPP) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CPP) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
