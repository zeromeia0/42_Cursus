/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:28:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:52:57 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_repetitive(int argc, char *argv[])
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 1;
	while (i < argc)
	{
		num_i = ft_atol(argv[i]);
		if (num_i > INT_MAX || num_i < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		j = i + 1;
		while (j < argc)
		{
			num_j = ft_atol(argv[j]);
			if (num_i == num_j)
				return (write(2, "Error\n", 6), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_stat(t_base_value *value)
{
	if (!value->stack || value->stack->stack_a_length < 1)
		return (0);
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

int	parsing(int argc, char *argv[], t_base_value *value)
{
	if (argc < 1)
		return (1);
	if (!nbr_nonum(argc, argv))
		return (super_duper_hiper_free(1), 0);
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
