# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 15:15:04 by fahmadia          #+#    #+#              #
#    Updated: 2024/01/16 20:38:49 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = ./srcs
SRCS = main.cpp\
	PhoneBook.cpp\
	Contact.cpp\
	add.cpp\
	search.cpp\
	trim.cpp\
	atoi.cpp\
	
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))
NAME = phonebook
CPP = c++
FLAGS = -c -g -Wall -Wextra -Werror -std=c++98
INCLUDE = ./include
HEADERS = $(INCLUDE)/Contact.hpp\
	$(INCLUDE)/PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJS)  $(HEADERS)
	$(CPP) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp Makefile 
	mkdir -p $(OBJS_DIR)
	$(CPP) $(FLAGS) -I$(INCLUDE) $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
