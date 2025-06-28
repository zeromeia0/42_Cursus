/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:51:29 by vivaz-ca         ###   ########.fr       */
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

void	sort_three(t_base_value *value)
{
	long	*a;

	a = value->stack->stack_a;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		single_swap(a, 3, 0);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		single_swap(a, 3, 0);
		reverse_rotate(a, value->stack, 0);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		single_rotate(a, value->stack, 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		reverse_rotate(a, value->stack, 0);
		single_swap(a, 3, 0);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
	{
		single_rotate(a, value->stack, 1);
		single_rotate(a, value->stack, 1);
	}
}

void	sort_five(t_base_value *v)
{
	while (v->stack->stack_a_length > 3)
	{
		v->min_in = find_smallest_index(v->stack->stack_a,
				v->stack->stack_a_length);
		v->lena = v->stack->stack_a_length;
		if (v->min_in <= v->lena / 2)
		{
			while (v->min_in-- > 0)
				single_rotate(v->stack->stack_a, v->stack, 1);
		}
		else
		{
			while (v->min_in++ < v->lena)
				reverse_rotate(v->stack->stack_a, v->stack, 0);
		}
		push_elements(v->stack->stack_a, v->stack->stack_b, v->stack, 1);
	}
	sort_three(v);
	if (v->stack->stack_b_length == 2
		&& v->stack->stack_b[0] < v->stack->stack_b[1])
		single_swap(v->stack->stack_b, v->stack->stack_b_length, 1);
	push_elements(v->stack->stack_b, v->stack->stack_a, v->stack, 0);
	push_elements(v->stack->stack_b, v->stack->stack_a, v->stack, 0);
	super_duper_hiper_free(1);
}

int	calculate_max_digits(long max)
{
	int	max_digits;

	max_digits = 0;
	while ((max >> max_digits) != 0)
		max_digits++;
	return (max_digits);
}
