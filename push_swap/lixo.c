/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lixo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:24:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 17:36:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_last_digit(int argc, char *argv[], t_base_value *value)
{
	int i = -1;
	long *array = copy_array(value);
	char *binary_str;

	(void)argc;
	(void)argv;
	index_it(value);
	while (++i < value->stack->stack_a_length)
	{
		binary_str = to_binary_string(value->stack->stack_a[i]);
		array[i] = ft_atol(binary_str); // This will now convert the binary string to a long
		printf("%ld ", array[i]);
	}
}

long to_binary_long(long num)
{
	long result = 0;
	long place = 1;

	while (num > 0)
	{
		result += (num % 2) * place;
		num /= 2;
		place *= 10;
	}
	return result;
}
long	*get_binary_array(long *input, int length)
{
	int i = 0;
	long *binary_array = malloc(sizeof(long) * (length));
	if (!binary_array)
		return (0);
	while (i < length)
	{
		binary_array[i] = to_binary_long(input[i]);
		i++;
	}
	return (binary_array);
}

void	make_binary(t_base_value *value)
{
	int i = 0;
	long *convert;

	convert = get_binary_array(value->stack->stack_a, value->stack->stack_a_length);
	while (i < value->stack->stack_a_length)
	{
		value->stack->stack_a[i] = convert[i];
		i++;
	}
}