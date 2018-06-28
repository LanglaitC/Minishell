# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/07 15:30:47 by clanglai          #+#    #+#              #
#    Updated: 2018/06/28 13:49:50 by clanglai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
NAME=minishell
INC=minishell.h
LIBC=libft/libftprintf.a
LIB_PATH =libft
LIB_NAME=lftprintf
PATH_SRC=srcs
SRC_FILE=minishell.c \
					ft_proc.c
SRCS= $(addprefix $(PATH_SRC)/, $(SRC_FILE))
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) -L$(LIB_PATH) -$(LIB_NAME)
	@echo "\033[1;34m$(ASM_NAME)\033[1;32m...compiled\t\t✓\033[0m"

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;34m$(COREWAR_NAME)\033[1;33m obj files removed\t\033[1;31m✓\033[0m"
	@echo "\033[1;34m$(ASM_NAME)\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\033[1;34m$(NAME)\033[1;33m exec removed\t\t\033[1;31m✓\033[0m"

re:
	@make fclean
	@make
