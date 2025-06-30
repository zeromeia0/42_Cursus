# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 16:31:31 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/06/30 16:33:49 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sla
SRCDIR = .
OBJDIR = objs

SRC = \
	$(SRCDIR)/main.c utils.c \

OBJS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) ./a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all

la: fclean

norm:
	@norminette | grep "c: Error"
	@echo "\nAmount of errors: " && norminette | grep "Error" | wc -l	

.PHONY: all clean fclean re val 