# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skythoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 09:02:29 by skythoma          #+#    #+#              #
#    Updated: 2019/06/05 12:54:56 by skythoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFILES = main.c parse.c

FLAGS = -Wall -Werror -Wextra 

GCC = gcc

LIBFT = libft

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling files . . .\033[0m"
	@make -C $(LIBFT)
	
	$(GCC) $(FLAGS) $(CFILES) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re
