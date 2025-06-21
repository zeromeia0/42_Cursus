/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:28:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 20:30:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_base_value *value;
	t_stack stack;
	int i;

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
	if (!parsing(argc, argv, value))
		return (0);

	index_it(value);

	long max = stack.stack_a_length - 1;
	int max_digits = 0;
	while ((max >> max_digits) != 0)
		max_digits++;
	value->max_digits = max_digits;

	radix_sort(value);

	print_stack("stack_a:\n", value->stack->stack_a,
		value->stack->stack_a_length);

	return (0);
}