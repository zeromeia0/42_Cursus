/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:28:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 16:46:07 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_repetitive(int argc, char *argv[])
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_printf(TWO_BIG), 0);
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (ft_printf("Erro\nTem numeros repetidos\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
int	check_stat(long *stk_x)
{
	if (!stk_x || stk_x[1] == '\0')
		return (printf("Error\nStack invalid\n"), 0);
	return (1);
}

int	already_sorted(t_base_value *value)
{
	int			i;
	static int	warn;
	long		*sorted;

	i = 0;
	sorted = quick_sort(value);
	while (i < value->stack->stack_a_length)
	{
		if (sorted[i] != value->stack->stack_a[i])
			warn++;
		i++;
	}
	if (warn == 0)
		return (0);
	return (1);
}

// IF INPUT = FRASE RETURN MALL
int	parsing(int argc, char *argv[], t_base_value *value)
{
	if (argc < 1)
		return (1);
	if (argc == 1)
		return (ft_printf("Erro\nColoca os argumentos\n"), 0);
	if (!find_repetitive(argc, argv))
		return (0);
	if (!check_stat(value->stack->stack_a))
		return (printf("Stack a nao pode tar vazio ou ser so um valor\n"), 0);
	if (!already_sorted(value))
		return (printf("Numeros ja estao em ordem\n"), 0);
	return (1);
}
