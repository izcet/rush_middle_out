# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 15:27:10 by irhett            #+#    #+#              #
#    Updated: 2017/07/09 17:42:04 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_retro

CXX			=	clang++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	src
SRC_FILE	=	main.cpp \
				Entity.class.cpp \
				World.class.cpp \
				Player.class.cpp \
				List.class.cpp \
				Enemy.class.cpp \
				Bullet.class.cpp \



SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC			=	-I src

.PHONY: re fclean clean all

all: $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CXX) $(INC) $(FLAGS) -l ncurses $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(INC) -c $^ $(FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
