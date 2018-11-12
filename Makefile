# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 10:34:36 by yyatsenk          #+#    #+#              #
#    Updated: 2018/02/19 10:34:37 by yyatsenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = yyatsenk.filler
VPATH = ./srcs/
HDIR = ./includes
PDIR = ./ft_printf
LDIR = ./libft

all : $(NAME)

$(NAME) :
	@echo "\033[34m\033[1mCompilation of the lib...\033[0m"
	@make -C $(LDIR) re
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation of printf...\033[0m"
	@make -C $(PDIR) re
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation of filler...\033[0m"
	@clang $(CFLAGS) -o $(NAME) ./src/*.c $(LDIR)/libft.a ft_printf/libftprintf.a
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mFiller done !\033[0m"

clean :
	@rm -f $(OBJ)
	@make -C $(LDIR) clean
	@make -C $(PDIR) clean

fclean : clean
	@rm -f $(NAME)
	@make -C $(LDIR) fclean
	@make -C $(PDIR) fclean

re : fclean all

.PHONY : all  clean fclean re
