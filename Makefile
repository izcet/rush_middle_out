# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 09:22:15 by rschramm          #+#    #+#              #
#    Updated: 2017/07/08 11:10:20 by rschramm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	early_riser
SRC		=	main.cpp Screen.cpp Menu.cpp Game.cpp Environment.cpp
OBJ		=	$(SRC:.cpp=.o)
FLAGS	=	-Wall -Wextra -Werror
CC		=	/usr/bin/clang++
RM		=	/bin/rm -rf
LIB		=	-lncurses -lmenu

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
	@echo "\033[33;32mSystem Ready >:D"

%.o: %.cpp
	@$(CC) -o $@ -c $< $(FLAGS) -g

clean:
	@$(RM) $(OBJ)
	@echo "\033[33mCleaned..."

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31mfCleaned..."

re: fclean all

.PHONY : re fclean clean all
