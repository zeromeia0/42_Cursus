# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 16:31:31 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/07/01 19:07:37 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = server.c utils.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette | grep "c: Error"
	@echo "\nAmount of errors: " && norminette | grep "Error" | wc -l	

.PHONY: all clean fclean re norm
