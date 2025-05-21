# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:39:51 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/05/21 08:25:31 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./main.c \
      ../gnl/get_next_line.c \
      ../gnl/get_next_line_utils.c \
      ../main/player_movement/movement_utils.c \
	  ../main/general/exit.c

OBJDIR = objs/
OBJS = $(patsubst ../%.c, $(OBJDIR)%.o, $(SRC))

MLX_FLAGS = -L. -lmlx -lXext -lX11
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)%.o: ../%.c
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


# NAME = so_long
# SRC = main.c \
# 	 assets.c \
# 	 gnl/get_next_line_utils.c \
# 	 gnl/get_next_line.c
	
# OBJDIR = objs/
# OBJ = $(SRC:.c=.o)
# OBJS = $(addprefix $(OBJDIR), $(OBJ))
# MLX_FLAGS = -L. -lmlx -lXext -lX11
# CC = cc
# CFLAGS = -g -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(OBJDIR) $(OBJS)
# 	cc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# $(OBJDIR)%.o: %.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJDIR):
# 	mkdir -p $(OBJDIR)

# clean:
# 	rm -rf $(OBJDIR)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all clean fclean re