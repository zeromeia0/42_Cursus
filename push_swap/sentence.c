/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:17:59 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:52:57 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_nonum(const char *str)
{
	int	i;

	i = 0;
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

int	nbr_nonum(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' '
					|| argv[i][j] == '+' || argv[i][j] == '-'))
				return (write(2, "Error\n", 6), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	init_stack_and_check(int argc, t_base_value *value, char **argv)
{
	int	i;

	if (!nbr_nonum(argc, argv))
		return (0);
	if (!ft_strchr(argv[1], ' '))
		return (0);
	if (argv[1][2] == '\0' || argv[1][1] == '\0')
		return (0);
	value->splited = ft_split(argv[1], ' ');
	if (!value->splited)
		return (0);
	i = 0;
	while (value->splited[i])
		i++;
	value->stack->stack_a_length = i;
	value->stack->stack_b_length = 0;
	value->stack->stack_a = malloc(sizeof(long) * i);
	value->stack->stack_b = malloc(sizeof(long) * i);
	if (!value->stack->stack_a || !value->stack->stack_b)
		return (super_duper_hiper_free(1), 0);
	return (i);
}

static int	process_numbers(t_base_value *value, int count)
{
	int	j;

	j = -1;
	while (++j < count)
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
	return (1);
}

int	sentence(int argc, char **argv, t_base_value *value)
{
	int	count;

	count = init_stack_and_check(argc, value, argv);
	if (!count)
		return (0);
	if (!process_numbers(value, count))
		return (0);
	if (count == 5)
	{
		sort_five(value);
		exit(0);
	}
	if (count == 3)
	{
		sort_three(value);
		super_duper_hiper_free(1);
		exit(0);
	}
	return (1);
}
