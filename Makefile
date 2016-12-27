# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 18:21:40 by hel-hadi          #+#    #+#              #
#    Updated: 2016/12/22 19:51:35 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = -I libft/ -I ./include
LIB = -L libft/ -lft
LIB_LINK = libft/libft.a
SRCS =	file_reader.c	\
 		check_map.c		\
		compare_list.c	\
		position.c 		\
		solver.c		\
		main_fillit.c	\
		solver_tool.c	\
		solver_tool_2.c	\

FILES = $(patsubst %, srcs/%,$(SRCS))
OBJET = $(patsubst %.c,%.o,$(SRCS))
CC = gcc
OPT2 = -o
FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(LIB_LINK)
	@echo "\033[34m === Creation du fichier executable ===\033[0m"
	$(CC) $(FLAGS) $(FILES) $(HEADER) $(LIB) -o $(NAME)

$(LIB_LINK):
	@make -C libft/

.PHONY		: clean fclean re

clean		:
		@make clean -C ./libft/
		rm -f $ $(OBJET)
		@echo "\033[36m ===	 Suppression des fichiers objets   ===\033[0m"

fclean		: clean
		@make fclean -C ./libft/
		rm -f $(NAME)
		@echo "\033[36m ===	 Supression du fichier executable   ===\033[0m"

re 			: fclean all
		@echo "\033[35m ===   Reinitialisation du programme Fillit   ===\033[0m"
