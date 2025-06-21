/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:28:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 16:28:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_base_value	*value;
// 	t_stack			stack;
// 	int				i;

// 	i = 0;
// 	value = malloc(sizeof(t_base_value));
// 	stack.stack_a_length = argc - 1;
// 	stack.stack_b_length = 0;
// 	stack.stack_a = malloc(sizeof(long) * (argc - 1));
// 	stack.stack_b = malloc(sizeof(long) * (argc - 1));
// 	if (!stack.stack_a || !stack.stack_b)
// 		return (printf("Malloc failed\n"), 1);
// 	value->stack = &stack;
// 	while (i < argc - 1)
// 	{
// 		stack.stack_a[i] = atol(argv[i + 1]);
// 		i++;
// 	}
// 	if (!parsing(argc, argv, stack.stack_a, stack.stack_a))
// 		return (0);

// 	index_it(value);

// 	// Push 5 elements from A to B
// 	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
// 	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
// 	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
// 	push_elements(stack.stack_a, stack.stack_b, &stack, 1);
// 	push_elements(stack.stack_a, stack.stack_b, &stack, 1);

// 	printf("\n==============================\n");
// 	printf("== After pushing 5 to Stack B ==\n");
// 	printf("==============================\n");

// 	printf("Stack A (%ld): ", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 	printf("[%ld] ", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 	printf("(empty)");
// 	printf("\n");

// 	printf("Stack B (%ld): ", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 	printf("[%ld] ", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 	printf("(empty)");
// 	printf("\n");
// 	single_rotate(value->stack->stack_a, value->stack, 1);
// 		printf("\n==============================\n");
// 	printf("== Single Rotate ==\n");
// 	printf("==============================\n");
// 		printf("Stack A (%ld): ", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 	printf("[%ld] ", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 	printf("(empty)");
// 	printf("\n");

// 	printf("Stack B (%ld): ", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 	printf("[%ld] ", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 	printf("(empty)");
// 	printf("\n");
// 	return (0);
// 	// Push 2 elements back to A
// 	push_elements(stack.stack_b, stack.stack_a, &stack, 0);
// 	push_elements(stack.stack_b, stack.stack_a, &stack, 0);

// 	printf("\n==============================\n");
// 	printf("== After pushing 2 to Stack A ==\n");
// 	printf("==============================\n");

// 	printf("Stack A (%ld): ", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 		printf("[%ld] ", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	printf("Stack B (%ld): ", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 		printf("[%ld] ", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	// Apply double_swap
// 	double_swap(&stack);
// 	printf("\n=========================\n");
// 	printf("== After double_swap ==\n");
// 	printf("=========================\n");
// 	printf("Stack A (%ld): ", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 		printf("[%ld] ", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	printf("Stack B (%ld): ", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 		printf("[%ld] ", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	// Apply double_rotate
// 	double_rotate(&stack);
// 	printf("\n==========================\n");
// 	printf("== After double_rotate ==\n");
// 	printf("==========================\n");
// 	printf("Stack A (%ld): ", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 		printf("[%ld] ", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	printf("Stack B (%ld): ", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 		printf("[%ld] ", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 		printf("(empty)");
// 	printf("\n");

// 	// Apply double_reverse_rotate
// 	double_reverse_rotate(&stack);
// 	printf("\n===============================\n");
// 	printf("== After double_reverse_rotate ==\n");
// 	printf("===============================\n");
// 	printf("Stack A (%ld):", stack.stack_a_length);
// 	for (i = 0; i < stack.stack_a_length; i++)
// 		printf(" [%ld]", stack.stack_a[i]);
// 	if (stack.stack_a_length == 0)
// 		printf("  (empty)\n");

// 	printf("\nStack B (%ld):", stack.stack_b_length);
// 	for (i = 0; i < stack.stack_b_length; i++)
// 		printf(" [%ld]", stack.stack_b[i]);
// 	if (stack.stack_b_length == 0)
// 		printf("  (empty)\n");

// 	printf("\n");

// 	free(stack.stack_a);
// 	free(stack.stack_b);
// 	free(value);
// 	return (0);
// }
