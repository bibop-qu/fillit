#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 15:10:33 by basle-qu          #+#    #+#              #
#    Updated: 2015/12/10 17:45:28 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = 	srcs/main.c \
		srcs/tools.c \
		srcs/init.c \
		srcs/verif.c
OBJS = 	main.o \
		tools.o \
		init.o \
		verif.o
NAME = fillit
CFLAG = -Wall -Wextra -Werror

.PHONY: all $(NAME) test clean fclean re

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean
	@gcc -I includes -c $(CFLAG) $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m########## FILLIT ##########\033[00m"
	@make clean

test: fclean
	@gcc -I includes -c $(CFLAG) -g $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m########## FILLIT ##########\033[00m"
	@make clean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

cleanall: fclean
	@make -C libft/ fclean

re: fclean $(NAME)