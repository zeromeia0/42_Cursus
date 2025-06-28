/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:46:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 20:33:55 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_push(long *src, long *dest, long *src_size, long *dest_size)
{
	int	i;

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
}

void	push_elements(long *src, long *dest, t_stack *stack, int which)
{
	long	*src_size;
	long	*dest_size;

	if (which == 1)
	{
		if (stack->stack_a_length == 0)
			return ;
		src_size = &stack->stack_a_length;
		dest_size = &stack->stack_b_length;
	}
	else
	{
		if (stack->stack_b_length == 0)
			return ;
		src_size = &stack->stack_b_length;
		dest_size = &stack->stack_a_length;
	}
	perform_push(src, dest, src_size, dest_size);
	if (which == 1)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

int	single_swap(long *stk_x, long len, int which)
{
	long	temp;

	if (!stk_x || len < 1)
		return (write(2, "Error\n", 6), 0);
	temp = stk_x[0];
	stk_x[0] = stk_x[1];
	stk_x[1] = temp;
	if (which == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	return (1);
}

void	single_rotate(long *stk_x, t_stack *stack, int which)
{
	long	i;
	long	temp;
	long	len;

	if (which == 1)
		len = stack->stack_a_length;
	else
		len = stack->stack_b_length;
	if (len < 1)
	{
		ft_printf("len pequena");
		return ;
	}
	temp = stk_x[0];
	i = 0;
	while (i < len - 1)
	{
		stk_x[i] = stk_x[i + 1];
		i++;
	}
	stk_x[len - 1] = temp;
	if (which == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(long *stk_x, t_stack *stack, int which)
{
	int		i;
	long	temp;
	long	len;

	if (which == 0)
		len = stack->stack_a_length;
	else
		len = stack->stack_b_length;
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
	if (which == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
