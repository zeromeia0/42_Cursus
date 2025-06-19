/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 17:24:44 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("%ld ", binary_array[i]);
		i++;
	}
	return (binary_array);
}



int	main(int argc, char **argv)
{
	t_base_value	*value;
	t_stack			stack;
	int				i;

	i = 0;
	value = malloc(sizeof(t_base_value));
	stack.stack_a_length = argc - 1;
	stack.stack_b_length = 0;
	stack.stack_a = malloc(sizeof(long) * (argc - 1));
	stack.stack_b = malloc(sizeof(long) * (argc - 1));
	if (!stack.stack_a || !stack.stack_b)
		return (printf("Malloc failed\n"), 1);
	value->stack = &stack;
	while (i < argc - 1)
	{
		stack.stack_a[i] = atol(argv[i + 1]);
		i++;
	}
	if (!parsing(argc, argv, stack.stack_a, stack.stack_a))
		return (0);
	
	index_it(value);
	get_binary_array(value->stack->stack_a, value->stack->stack_a_length);
	
	return (0);
}