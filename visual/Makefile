# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/05/29 14:17:47 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = visual
VPATH = ./srcs/
HDIR = ./includes
LDIR = ./libft

all : $(NAME)

$(NAME) : 
	@echo "\033[34m\033[1mCompilation de la lib...\033[0m"
	@make -C $(LDIR) re
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation of printf...\033[0m"
	@make -C ./ft_printf re
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation bonus...\033[0m"
	@clang $(CFLAGS) -I /usr/local/include/ ./*.c -L /usr/local/bin -lmlx -framework OpenGL\
	 -framework AppKit libft/libft.a ft_printf/libftprintf.a -o $(NAME)
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mBonus done !\033[0m"

clean :
	@rm -f ./*.o
	@make -C $(LDIR) clean
	@make -C ./ft_printf clean
fclean : clean
	@rm -f $(NAME)
	@make -C $(LDIR) fclean
	@make -C ./ft_printf fclean
re : fclean all

.PHONY : all  clean fclean re
