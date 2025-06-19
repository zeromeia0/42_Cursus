/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 14:16:18 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_last_digit(int argc, char *argv[], t_base_value *value)
{
	(void)argv;
	index_it(value);
	print_stack("Stack_a: ", value->stack->stack_a, value->stack->stack_a_length);
	get_most_digits(argc, value, &value->max_digits);
	
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
		
	get_last_digit(argc, argv, value);
	return (0);
}