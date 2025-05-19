# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:39:51 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/05/19 14:34:25 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c
OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
MLX_FLAGS = -L. -lmlx -lXext -lX11
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re