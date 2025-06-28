/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:53:02 by vivaz-ca         ###   ########.fr       */
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
# include <strings.h>
# include <unistd.h>
# define TWO_BIG "Error\n"

typedef struct s_stack
{
	long		*stack_a;
	long		*stack_b;
	long		stack_a_length;
	long		stack_b_length;
}				t_stack;

typedef struct s_base_values
{
	int			min_in;
	int			lena;
	int			i;
	int			j;
	long		max_digits;
	long		received_number;
	char		**splited;
	t_stack		*stack;
}				t_base_value;

int				find_repetitive(int argc, char *argv[]);
int				parsing(int argc, char *argv[], t_base_value *value);
int				ft_strcmp(char *s1, char *s2);
int				minimum_len(long *stk);
int				check_stat(t_base_value *value);
int				single_swap(long *stk_x, long len, int which);
int				index_it(t_base_value *value);
int				get_most_digits(int argc, t_base_value *value,
					long *max_digits);
void			print_stuff(int argc, char *argv[], t_base_value *print);
long			ft_atol(char *str);
long			count_digits(long nb);

void			push_elements(long *src, long *dest, t_stack *stack, int which);
void			double_swap(t_stack *stack);
void			single_rotate(long *stk_x, t_stack *stack, int which);
void			double_rotate(t_stack *stack);
void			reverse_rotate(long *stk_x, t_stack *stack, int which);
void			double_reverse_rotate(t_stack *stack);
void			print_stack(const char *name, long *stack, int size);
long			*copy_array(t_base_value *value);
long			*quick_sort(t_base_value *value);
void			radix_sort(t_base_value *value);
void			super_duper_hiper_free(int chama);
t_base_value	*value(void);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(const char *s, char c);
int				sentence(int argc, char **argv, t_base_value *value);
char			*ft_strchr(const char *s, int c);
void			sort_five(t_base_value *value);
int				str_nonum(const char *str);
int				nbr_nonum(int argc, char *argv[]);
void			sort_three(t_base_value *value);
void			free_split(char **arr);
int				find_smallest_index(long *arr, int size);
void			perform_push(long *src, long *dest, long *src_size,
					long *dest_size);
long			count_digits_loser(long nb);
int				calculate_max_digits(long max);

#endif