/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/14 17:12:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_base_value	*value(void)
{
	static t_base_value	value;

	return (&value);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long	count_digits(long nb)
{
	long	count;

	count = 1;
	if (nb >= 0 && nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	get_most_digits(int argc, char *argv[], long *max_digits)
{
	int	i;

	i = 1;
	*max_digits = count_digits(ft_atol(argv[i]));
	while (i < argc)
	{
		if (*max_digits < count_digits(ft_atol(argv[i + 1])))
			*max_digits = count_digits(ft_atol(argv[i + 1]));
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	receive_values(int argc, char **argv, long **stack_a)
{
	int	i;

	i = 0;
	*stack_a = malloc(sizeof(long) * (argc - 1));
	if (!*stack_a)
		return (1);
	while (i < argc - 1)
	{
		(*stack_a)[i] = ft_atol(argv[i + 1]);
		printf("Stack[%d]: %ld\n", i, (*stack_a)[i]);
		i++;
	}
	return (0);
}

void	print_stuff(int argc, char *argv[], t_base_value *print)
{
	int i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("Digits: %ld\t| Argv[%d]: %ld\n",
				count_digits(ft_atol(argv[i])), i, ft_atol(argv[i]));
			i++;
		}
	}
	get_most_digits(argc, argv, &print->max_digits);
	printf("Max digits: %ld\n", print->max_digits);
}
