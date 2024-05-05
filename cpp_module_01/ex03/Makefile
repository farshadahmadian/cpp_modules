# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 20:49:25 by fahmadia          #+#    #+#              #
#    Updated: 2024/01/18 20:51:13 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = HumanA.cpp\
	HumanB.cpp\
	main.cpp\
	Weapon.cpp
	
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
NAME =  attack
CPP = c++
FLAGS = -c -g -Wall -Wextra -Werror -std=c++98

HEADERS = HumanA.hpp\
	HumanB.hpp\
	Weapon.hpp

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
