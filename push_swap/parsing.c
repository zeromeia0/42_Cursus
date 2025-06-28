/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:28:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:02:55 by vivaz-ca         ###   ########.fr       */
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
			return (ft_printf(TWO_BIG), 0);
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

int str_nonum(const char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int nbr_nonum(int argc, char *argv[])
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-'))
				return(write(2, "Error\n", 6), 0);
			j++;
		}
		i++;
	}
	return (1);
}


int	sentence(int argc, char **argv, t_base_value *value)
{
	int i = 0;

	if (!nbr_nonum(argc, argv))
		return (0);
	if (!ft_strchr(argv[1], ' '))
		return (0);
	if (argv[1][2] == '\0' || argv[1][1] == '\0')
		return (0);
	value->splited = ft_split(argv[1], ' ');
	if (!value->splited)
		return (0);
	while (value->splited[i])
		i++;
	value->stack->stack_a_length = i;
	value->stack->stack_b_length = 0;
	value->stack->stack_a = malloc(sizeof(long) * i);
	value->stack->stack_b = malloc(sizeof(long) * i);
	if (!value->stack->stack_a || !value->stack->stack_b)
		return (super_duper_hiper_free(1), 0);
	for (int j = 0; j < i; j++)
	{
		if (!str_nonum(value->splited[j]))
		{
			write(2, "Error\n", 6);
			super_duper_hiper_free(1);
			exit(1);
		}
		value->stack->stack_a[j] = ft_atol(value->splited[j]);
	}
	index_it(value);
	if (i == 5)
	{
		sort_five(value);
		exit(0);
	}
	if (i == 3)
	{
		sort_three(value);
		super_duper_hiper_free(1);
		exit(0);
	}
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
