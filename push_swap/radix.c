/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:36:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/26 17:16:09 by vivaz-ca         ###   ########.fr       */
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

void sort_three(t_base_value *value)
{
    long *a = value->stack->stack_a;

    if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])  // Case: 2 1 3
        single_swap(a, 3, 0);
    else if (a[0] > a[1] && a[1] > a[2])  // Case: 3 2 1
    {
        single_swap(a, 3, 0);
        reverse_rotate(a, value->stack, 0);
    }
    else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])  // Case: 3 1 2
       single_rotate(a, value->stack, 1);
    else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])  // Case: 1 3 2
    {
		reverse_rotate(a, value->stack, 0);
		single_swap(a, 3, 0);
	}
    else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])  // Case: 2 3 1
    {
        single_rotate(a, value->stack, 1);
        single_rotate(a, value->stack, 1);
    }
	// print_stack("Final stack: ", value->stack->stack_a, value->stack->stack_a_length);
	super_duper_hiper_free(1);
}

void	sort_five(t_base_value *value)
{
	int	min_index;
	int	len;

	while (value->stack->stack_a_length > 3)
	{
		min_index = find_smallest_index(value->stack->stack_a, value->stack->stack_a_length);
		len = value->stack->stack_a_length;
		if (min_index <= len / 2)
		{
			while (min_index-- > 0)
				single_rotate(value->stack->stack_a, value->stack, 1); // 🔁 USE 1 instead of 0
		}
		else
		{
			while (min_index++ < len)
				reverse_rotate(value->stack->stack_a, value->stack, 0); // rra works fine
		}
		push_elements(value->stack->stack_a, value->stack->stack_b, value->stack, 1); // pb
	}
	sort_three(value);
	if (value->stack->stack_b[0] < value->stack->stack_b[1])
		single_swap(value->stack->stack_b, value->stack->stack_b_length, 1); // sb
	push_elements(value->stack->stack_b, value->stack->stack_a, value->stack, 0); // pa
	push_elements(value->stack->stack_b, value->stack->stack_a, value->stack, 0); // pa

	super_duper_hiper_free(1);
}