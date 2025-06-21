/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 17:48:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_base_value *value)
{
	int	bit;
	int	count;
	int	i;

	bit = 0;
	while (bit < value->max_digits)
	{
		i = 0;
		count = value->stack->stack_a_length;
		while (i < count)
		{
			if (((value->stack->stack_a[0] >> bit) & 1) == 0)
				push_elements(value->stack->stack_a, value->stack->stack_b,
					value->stack, 1);
			else
				single_rotate(value->stack->stack_a, value->stack, 1);
			i++;
		}
		while (value->stack->stack_b_length > 0)
			push_elements(value->stack->stack_b, value->stack->stack_a,
				value->stack, 0);
		bit++;
	}
}
