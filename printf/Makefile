# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:28:19 by aatan             #+#    #+#              #
#    Updated: 2024/01/31 18:39:26 by aatan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = ft_printf.c \
				ft_write_args.c \
				ft_write_argsnum.c \
				ft_libft.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@
		@echo "--> Compiled $<"

$(NAME): $(OBJ)
		$(AR) rcs $(NAME) $(OBJ)
		@echo "--> Library $@ created"

clean:
	rm -rf $(OBJ)
		@echo "--> Removing $(OBJ)"

fclean: clean
			rm -f $(NAME)
			@echo "--> Removing $(NAME)"

re: fclean all

.PHONY: all clean fclean re

