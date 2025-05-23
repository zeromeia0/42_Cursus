# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:39:51 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/05/23 19:19:07 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = so_long

# Directories
SRCDIR = .
OBJDIR = objs
MLXDIR = ../0-minilibx-linux
GNL_DIR = ../0-gnl
MAP_DIR = ../map
TEXTURE_DIR = ../0-textures
PLAYER_DIR = ../2-player_movement
GATO_DIR = ../2-gato
GEN_DIR = ../2-general

# Sources
SRC = \
	$(SRCDIR)/main.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(PLAYER_DIR)/movement_utils.c \
	$(GEN_DIR)/exit.c \
	$(MAP_DIR)/convert_map.c \
	$(MAP_DIR)/init_map.c \
	$(GATO_DIR)/gato_utils.c

# Object files
OBJS = $(SRC:../%.c=$(OBJDIR)/%.o)
OBJS := $(OBJS:./%.c=$(OBJDIR)/%.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Minilibx flags
MLX_FLAGS = -L . -lmlx -lXext -lX11
INCLUDES = -I$(MLXDIR) -I$(GNL_DIR) -I. -I$(MAP_DIR) -I$(PLAYER_DIR) -I$(GEN_DIR) -I$(GATO_DIR)

# Build rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# NAME = so_long

# SRC = ./main.c \
#       ../gnl/get_next_line.c \
#       ../gnl/get_next_line_utils.c \
#       ../main/player_movement/movement_utils.c \
# 	  ../main/general/exit.c

# OBJDIR = objs/
# OBJS = $(patsubst ../%.c, $(OBJDIR)%.o, $(SRC))

# MLX_FLAGS = -L. -lmlx -lXext -lX11
# CC = cc
# CFLAGS = -g -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(OBJDIR) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# $(OBJDIR)%.o: ../%.c
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