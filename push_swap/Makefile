# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 08:56:04 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/06/14 13:46:12 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = .
OBJDIR = objs
PRINTF_DIR = ./my_printf

SRC = \
	$(SRCDIR)/utils.c main.c parsing.c \
	$(PRINTF_DIR)/printf_utils.c \
	$(PRINTF_DIR)/printf_utils2.c \
	$(PRINTF_DIR)/libft_functions.c \
	$(PRINTF_DIR)/ft_itoa.c

OBJS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS := $(OBJS:$(PRINTF_DIR)/%.c=$(OBJDIR)/$(PRINTF_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
