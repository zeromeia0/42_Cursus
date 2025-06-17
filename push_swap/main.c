/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:50 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/17 15:32:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i = 0;

	stack.stack_a_length = argc - 1;
	stack.stack_b_length = 0;
	stack.stack_a = malloc(sizeof(long) * (argc - 1));
	stack.stack_b = malloc(sizeof(long) * (argc - 1));
	if (!stack.stack_a || !stack.stack_b)
		return (printf("Malloc failed\n"), 1);

	while (i < argc - 1)
	{
		stack.stack_a[i] = atol(argv[i + 1]);
		i++;
	}
	if (!parsing(argc, argv, stack.stack_a, stack.stack_a))
		return (0);
	printf("== Initial stack_a: == \n");
	for (i = 0; i < stack.stack_a_length; i++)
		printf("[%ld] ", stack.stack_a[i]);
	printf("\n");
	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
	printf("== After pushing two elements to B: == \n");
	printf("\nStack_a: ");
	for (i = 0; i < stack.stack_a_length; i++)
		printf("[%ld]", stack.stack_a[i]);
	printf("\n");
	printf("\nStack_b: ");
	for (i = 0; i < stack.stack_b_length; i++)
		printf("[%ld]", stack.stack_b[i]);
	printf("\n");
	double_swap(&stack);
	printf("== After double_swap: == \n");
	printf("\nStack_a: ");
	for (i = 0; i < stack.stack_a_length; i++)
		printf("[%ld]", stack.stack_a[i]);
	printf("\n");
	printf("\nStack_b: ");
	for (i = 0; i < stack.stack_b_length; i++)
		printf("[%ld]", stack.stack_b[i]);
	printf("\n");
	double_rotate(&stack);
	printf("== After double_rotate: == \n");
	printf("\nStack_a: ");
	for (i = 0; i < stack.stack_a_length; i++)
		printf("[%ld]", stack.stack_a[i]);
	printf("\n");
	printf("\nstack_b: ");
	for (i = 0; i < stack.stack_b_length; i++)
		printf("[%ld]", stack.stack_b[i]);
	printf("\n");
	printf("== After reverse rotate: == \n");
	double_reverse_rotate(&stack);
	for (i = 0; i < stack.stack_a_length; i++)
		printf("Stack_a:[%ld]\n", stack.stack_a[i]);
	for (i = 0; i < stack.stack_b_length; i++)
		printf("Stack_b:[%ld]\n", stack.stack_b[i]);
	printf("\n");
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
