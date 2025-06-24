/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:28:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/24 17:19:55 by vivaz-ca         ###   ########.fr       */
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
				return (ft_printf("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
int	check_stat(t_base_value *value)
{
	if (!value->stack || value->stack->stack_a_length <= 2)
		return (ft_printf("Error\n"), 0);
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
		return (free(sorted), 0);
	free(sorted);
	return (1);
}


// IF INPUT = FRASE RETURN MALL
int	parsing(int argc, char *argv[], t_base_value *value)
{
	if (argc < 1)
		return (1);
	if (argc == 1)
		return (0);
	if (!find_repetitive(argc, argv))
		return (super_duper_hiper_free(1), 0);
	if (!check_stat(value))
		return (super_duper_hiper_free(1), 0);
	if (!already_sorted(value))
		return (super_duper_hiper_free(1), 0);
	return (1);
}
