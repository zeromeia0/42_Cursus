/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:46:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 16:24:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elements(long *src, long *dest, t_stack *stack, int which)
{
	int		i;
	long	*src_size;
	long	*dest_size;

	if (which && stack->stack_a_length == 0)
		return ;
	if (!which && stack->stack_b_length == 0)
		return ;
	src_size = which ? &stack->stack_a_length : &stack->stack_b_length;
	dest_size = which ? &stack->stack_b_length : &stack->stack_a_length;
	i = *dest_size;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];
	(*dest_size)++;
	i = 0;
	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
	if (which == 1)
		printf("pb\n");
	else
		printf("pa\n");
}

int	single_swap(long *stk_x, int(f)(long *))
{
	long	temp;

	if (!stk_x || (f)(stk_x) < 2)
		return (printf("Error\nArray nao tem tamanho\n"), 0);
	temp = stk_x[0];
	stk_x[0] = stk_x[1];
	stk_x[1] = temp;
	return (1);
}

void	double_swap(t_stack *stack)
{
	if (stack->stack_a_length < 2)
	{
		printf("Stack_a ta vazio\n");
		return ;
	}
	if (stack->stack_b_length < 2)
	{
		printf("Stack_b ta vazio\n");
		return ;
	}
	single_swap(stack->stack_a, minimum_len);
	single_swap(stack->stack_b, minimum_len);
	printf("ss\n");
}

void	single_rotate(long *stk_x, t_stack *stack, int which)
{
	long	i;
	long	temp;
	long	len;

	len = which == 1 ? stack->stack_a_length : stack->stack_b_length; // FIXED
	if (len < 2)
		return ;
	temp = stk_x[0];
	i = 0;
	while (i < len - 1)
	{
		stk_x[i] = stk_x[i + 1];
		i++;
	}
	stk_x[len - 1] = temp;
	if (which == 1)
		printf("ra\n");
	else
		printf("rb\n");
}

void	double_rotate(t_stack *stack)
{
	if (stack->stack_a_length < 2)
	{
		printf("Stack_a ta vazio\n");
		return ;
	}
	if (stack->stack_b_length < 2)
	{
		printf("Stack_b ta vazio\n");
		return ;
	}
	single_rotate(stack->stack_a, stack, 0);
	single_rotate(stack->stack_b, stack, 1);
	printf("rr\n");
}

void	reverse_rotate(long *stk_x, t_stack *stack, int which)
{
	int		i;
	long	temp;
	long	len;

	len = (which == 0) ? stack->stack_a_length : stack->stack_b_length;
	if (len < 2)
		return ;
	temp = stk_x[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stk_x[i] = stk_x[i - 1];
		i--;
	}
	stk_x[0] = temp;
	if (which == 1)
		printf("rra\n");
	else
		printf("rrb\n");
}

void	double_reverse_rotate(t_stack *stack)
{
	reverse_rotate(stack->stack_a, stack, 0);
	reverse_rotate(stack->stack_b, stack, 1);
	printf("rrr\n");
}
