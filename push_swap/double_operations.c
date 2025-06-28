/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:09:14 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:10:49 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack *stack)
{
	if (stack->stack_a_length < 2)
	{
		ft_printf("Stack_a ta vazio\n");
		return ;
	}
	if (stack->stack_b_length < 2)
	{
		ft_printf("Stack_b ta vazio\n");
		return ;
	}
	single_swap(stack->stack_a, stack->stack_a_length, 0);
	single_swap(stack->stack_b, stack->stack_b_length, 1);
	ft_printf("ss\n");
}

void	double_rotate(t_stack *stack)
{
	if (stack->stack_a_length < 2)
	{
		ft_printf("Stack_a ta vazio\n");
		return ;
	}
	if (stack->stack_b_length < 2)
	{
		ft_printf("Stack_b ta vazio\n");
		return ;
	}
	single_rotate(stack->stack_a, stack, 0);
	single_rotate(stack->stack_b, stack, 1);
	ft_printf("rr\n");
}

void	double_reverse_rotate(t_stack *stack)
{
	reverse_rotate(stack->stack_a, stack, 0);
	reverse_rotate(stack->stack_b, stack, 1);
	ft_printf("rrr\n");
}
