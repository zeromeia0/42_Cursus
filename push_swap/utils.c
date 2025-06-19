/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 17:46:39 by vivaz-ca         ###   ########.fr       */
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


long	count_digits_loser(long nb)
{
	long	count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
long count_digits(long nb)
{
	long count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int get_most_digits(int argc, t_base_value *value, long *max_digits)
{
	int i;

	i = 0;
	*max_digits = count_digits(value->stack->stack_a[i]);
	while (++i < argc - 1)
	{
		long digits = count_digits(value->stack->stack_a[i]);
		if (*max_digits < digits)
			*max_digits = digits;
	}
	return (int)(*max_digits);
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

void	print_stuff(int argc, char *argv[], t_base_value *print)
{
	int	i;

	i = 1;
	(void)print;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("Digits: %ld\t| Argv[%d]: %ld\n",
				count_digits_loser(ft_atol(argv[i])), i, ft_atol(argv[i]));
			i++;
		}
	}
}

void	print_stack(const char *name, long *stack, int size)
{
	printf("%s: ", name);
	for (int i = 0; i < size; i++)
		printf("%ld ", stack[i]);
	printf("\n");
}

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