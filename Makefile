# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 15:27:10 by irhett            #+#    #+#              #
#    Updated: 2017/07/09 22:37:48 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_retro

CXX			=	clang++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

MINI_DIR	=	mini
MINI_FILE	=	main.cpp \
				Entity.class.cpp \
				World.class.cpp \
				Player.class.cpp \
				List.class.cpp \
				Enemy.class.cpp \
				Bullet.class.cpp \



MINI		=	$(addprefix $(MINI_DIR)/, $(MINI_FILE))

MOB_DIR		=	obj
MOB_FILE	=	$(MINI_FILE:.cpp=.o)
MOBS		=	$(addprefix $(MOB_DIR)/, $(MOB_FILE))

INK			=	-I mini

.PHONY: re fclean clean all

all: $(NAME)

$(NAME): $(MINIS) | $(OBJS) | $(MINI) | $(MOBS)
	$(CXX) $(INC) $(FLAGS) -l ncurses $(OBJS) -o $(NAME)
	$(CXX) $(INK) $(FLAGS) -l ncurses $(MOBS) -o minigame

$(MOB_DIR)/%.o: $(MINI_DIR)/%.cpp | $(MOB_DIR)
	@$(CXX) $(INC) -c $^ $(FLAGS) -o $@

$(MOB_DIR):
	@mkdir -p $(MOB_DIR)

clean:
	rm -rf $(MOB_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
