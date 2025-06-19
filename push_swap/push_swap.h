/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 14:12:24 by vivaz-ca         ###   ########.fr       */
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
	long		stack_a_length;
	long		stack_b_length;
}				t_stack;

typedef struct s_base_values
{
	long		max_digits;
	long		received_number;
	t_stack		*stack;
}				t_base_value;

int				find_repetitive(int argc, char *argv[]);
int				parsing(int argc, char *argv[], long *stk_a, long *stk_b);
int				ft_strcmp(char *s1, char *s2);
int				receive_values(int argc, char **argv, long **stack_a);
int				minimum_len(long *stk);
int				check_stat(long *stk_x);
int				single_swap(long *stk_x, int(f)(long *));
int				index_it(t_base_value *value);
void	get_most_digits(int argc, t_base_value *value, long *max_digits);
void			print_stuff(int argc, char *argv[], t_base_value *print);
long			ft_atol(char *str);
long count_digits(long nb);

void			push_elements(long *src, long *dest, t_stack *stack, int which);
void			double_swap(t_stack *stack);
void			single_rotate(long *stk_x, t_stack *stack, int which);
void			double_rotate(t_stack *stack);
void			reverse_rotate(long *stk_x, t_stack *stack, int which);
void			double_reverse_rotate(t_stack *stack);
void			print_stack(const char *name, long *stack, int size);
t_base_value	*value(void);

#endif