/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:37:04 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:40:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum_len(long *stk)
{
	if (!stk)
		return (0);
	if (stk[0] && stk[1])
		return (2);
	if (stk[0])
		return (1);
	return (0);
}

int	five_elements(int argc, char *argv[], t_base_value *value)
{
	int	j;

	j = 0;
	(void)argc;
	(void)argv;
	value->stack->stack_a_length = 5;
	value->stack->stack_b_length = 0;
	value->stack->stack_a = malloc(sizeof(long) * 5);
	value->stack->stack_b = malloc(sizeof(long) * 5);
	if (!value->stack->stack_a || !value->stack->stack_b)
		return (free(value->stack->stack_a), free(value->stack->stack_b),
			free(value->stack), 0);
	while (++j < 6)
		value->stack->stack_a[j] = ft_atol(value->splited[j]);
	index_it(value);
	return (1);
}

int	find_smallest_index(long *arr, int size)
{
	int	i;
	int	min_i;

	i = 0;
	min_i = 0;
	while (i < size)
	{
		if (arr[i] < arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

void	print_stuff(int argc, char *argv[], t_base_value *print)
{
	int	i;

	i = 1;
	(void)print;
	if (argc >= 2)
	{
		while (i < argc)
		{
			ft_printf("Digits: %ld\t| Argv[%d]: %ld\n",
				count_digits_loser(ft_atol(argv[i])), i, ft_atol(argv[i]));
			i++;
		}
	}
}

void	print_stack(const char *name, long *stack, int size)
{
	int	i;

	i = -1;
	ft_printf("%s", name);
	while (++i < size)
		ft_printf("[%ld] ", stack[i]);
	ft_printf("\n");
}
