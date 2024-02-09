# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:32:03 by aatan             #+#    #+#              #
#    Updated: 2024/02/06 12:51:13 by aatan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ft_printf server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server -Lprintf -lftprintf

client: client.c
	$(CC) $(CFLAGS) client.c ft_atoi.c -o client -Lprintf -lftprintf

bonus: ft_printf client_bonus server_bonus

server_bonus: bonus/server_bonus.c
	$(CC) $(CFLAGS) bonus/server_bonus.c -o server_bonus -Lprintf -lftprintf

client_bonus: bonus/client_bonus.c
	$(CC) $(CFLAGS) bonus/client_bonus.c ft_atoi.c -o client_bonus -Lprintf -lftprintf

ft_printf:
	$(MAKE) -C ./printf

clean:
	$(MAKE) clean -C ./printf
	rm -rf server client
	rm -rf server_bonus client_bonus
	@echo " >> clean"

fclean: clean
	$(MAKE) fclean -C ./printf
	rm -f server client server_bonus client_bonus
	@echo " >> Full Clean"

re: fclean all

.PHONY: all clean fclean re bonus
