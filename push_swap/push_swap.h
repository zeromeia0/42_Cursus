/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/14 17:00:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./my_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TWO_BIG "Erro\nNumero maior que INT_MAX ou menor que INT_MIN\n"

typedef struct s_stack
{
	long		*stack_a;
	long		*stack_b;
}				t_stack;

typedef struct s_base_values
{
	long		max_digits;
	t_stack		*stack;
}				t_base_value;

int				find_repetitive(int argc, char *argv[]);
int				parsing(int argc, char *argv[]);
int				ft_strcmp(char *s1, char *s2);
int				receive_values(int argc, char **argv, long **stack_a);
void			get_most_digits(int argc, char *argv[], long *max_digits);
void			print_stuff(int argc, char *argv[], t_base_value *print);
long			ft_atol(char *str);
long			count_digits(long nb);
t_base_value	*value(void);

#endif