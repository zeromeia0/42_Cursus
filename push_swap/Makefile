# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 08:56:04 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/06/24 17:22:50 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = .
OBJDIR = objs
PRINTF_DIR = ./my_printf

SRC = \
	$(SRCDIR)/utils.c main.c parsing.c operations.c indexing.c radix.c goated_split.c free.c\
	$(PRINTF_DIR)/printf_utils.c \
	$(PRINTF_DIR)/printf_utils2.c \
	$(PRINTF_DIR)/printf_utils3.c \
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
	rm -rf $(OBJDIR) ./a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

val:
	@echo "======= TESTE 1 =======\npush_swap 1\n"
	@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1

	@echo "\n======= TESTE 2 =======\npush_swap 1 2\n"
	@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 2

	@echo "\n======= TESTE 3 =======\npush_swap 1 2 5 4\n"
	@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 2 5 4

	@echo "\n======= TESTE 4 =======\npush_swap 1 2 3\n"
	@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 2 3
	

.PHONY: all clean fclean re
