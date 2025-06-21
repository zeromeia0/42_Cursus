/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 14:59:15 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void lsd_zero(t_base_value *value)
{
    int i = 0;
    long count = value->stack->stack_a_length;
    
    while (i < count)
    {
        if ((value->stack->stack_a[0] & 1) == 0)
            push_elements(value->stack->stack_a, value->stack->stack_b, value->stack, 1);
        else
            single_rotate(value->stack->stack_a, value->stack, 1);
        i++;
    }
}

int main(int argc, char *argv[])
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
	printf("\n=======\nPushing to b if binary is zero\n=======\n");
	print_stack("stack_a:\n", value->stack->stack_a, value->stack->stack_a_length);
	lsd_zero(value);
	print_stack("stack_a:\n", value->stack->stack_a, value->stack->stack_a_length);
	print_stack("stack_b:\n", value->stack->stack_b, value->stack->stack_b_length);
	return (0);
}