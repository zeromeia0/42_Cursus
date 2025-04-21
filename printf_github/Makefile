# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 22:43:31 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/04/21 21:14:59 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

ASSETS_DIR = assets
ASSETS_SRC = $(ASSETS_DIR)/ft_itoa.c $(ASSETS_DIR)/libft_functions.c

SRC = ft_printf.c \
      ft_print_char.c \
      ft_print_dec_int.c \
      ft_print_hexa.c \
      ft_print_ptr.c \
      ft_print_str.c \
      ft_print_unsigned_int.c \
      $(ASSETS_SRC)

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
