# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 08:56:04 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/06/28 15:39:13 by vivaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = .
OBJDIR = objs
PRINTF_DIR = ./my_printf

SRC = \
	$(SRCDIR)/utils.c main.c parsing.c operations.c indexing.c radix.c goated_split.c free.c double_operations.c sentence.c utils2.c digits.c\
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
	@rm -rf $(OBJDIR) ./a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all

la: fclean

norm:
	@norminette | grep "c: Error"
	@echo "\nAmount of errors: " && norminette | grep "Error" | wc -l
	
sentence: re
	@echo "Testand frase com 9 23 17 52 -9"
	@./push_swap "9 23 17 52 -9"

proof: re
	@echo "Testando com o checker"
	@ARG="$$(shuf -i 1-100 -n 100 | tr '\n' ' ')"; \
	./push_swap $$ARG | ./checker_linux $$ARG

count_one: re
	@ARG="$$(shuf -i 1-100 -n 100 | tr '\n' ' ')"; \
	./push_swap $$ARG | wc -l

count_two: re
	@ARG="$$(shuf -i 1-900 -n 500 | tr '\n' ' ')"; \
	./push_swap $$ARG | wc -l
	
cem: re
	@echo "Testando com 100 numeros: \n"
	@./push_swap $$(shuf -i 1-100 -n 100)
	
vcem: re
	@echo "Testando com 100 numeros: \n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap $$(shuf -i 1-100 -n 100)

quin: re
	@echo "Testando com 500 numeros: \n"
	@./push_swap $$(shuf -i 1-500 -n 500)

vquin: re
	@echo "Testando com 500 numeros: \n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap $$(shuf -i 1-500 -n 500)

strval: re
	@echo "======= TESTE 1 =======\npush_swap 1\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "1"

	@echo "\n======= TESTE 2 =======\npush_swap 1 2\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "1 2"

	@echo "\n======= TESTE 3 =======\npush_swap 1 2 5 4\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "1 2 5 4"

	@echo "\n======= TESTE 4 =======\npush_swap 1 2 3\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "1 2 3"
	
	@echo "\n======= TESTE 5 =======\npush_swap 9 1 33 -3 12\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "9 1 33 -3 12"

nbrval: re
	@echo "======= TESTE 1 =======\npush_swap 1\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1

	@echo "\n======= TESTE 2 =======\npush_swap 1 2 3\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 2 3

	@echo "\n======= TESTE 3 =======\npush_swap 1 2 5 4\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 2 5 4

	@echo "\n======= TESTE 4 =======\npush_swap 1 3 2\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 1 3 2 

	@echo "\n======= TESTE 5 =======\npush_swap 9 1 33 -3 12\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 9 1 33 -3 12
	

.PHONY: all clean fclean re val 
