/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chuncks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:03:27 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 19:58:11 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int len)
{
	if (len <= 100)
		return (len / 5);
	return (len / 11);
}

void	sort_using_chunks(long *stk_a, long *stk_b, t_base_value *value)
{
	long	*sorted;
	int		len = value->stack->stack_a_length;
	static int		i;
	int j, chunk_number;
	
	sorted= quick_sort(value);
	while (i < len)
	{
		chunk_number = i + get_chunk_size(len);
		while ((value->stack->stack_a_length > 0) && (i < chunk_number) && (i < len))
		{
			j = 0;
			while (j < value->stack->stack_a_length)
			{
				if (stk_a[j] >= sorted[i] && stk_a[j] <= sorted[chunk_number - 1])
				{
					if (j <= value->stack->stack_a_length / 2)
						while (j-- > 0)
							single_rotate(stk_a, value->stack, 0); // ra
					else
						while (j++ < value->stack->stack_a_length)
							reverse_rotate(stk_a, value->stack, 0); // rra
					push_elements(stk_a, stk_b, value->stack, 1); // pb
					break ;
				}
				j++;
			}
		}
		i = chunk_number;
	}
	while (value->stack->stack_b_length > 0)
	{
		int max_i = find_max_index(stk_b, value->stack->stack_b_length);
		if (max_i <= value->stack->stack_b_length / 2)
			while (max_i-- > 0)
				single_rotate(stk_b, value->stack, 1); // rb
		else
			while (max_i++ < value->stack->stack_b_length)
				reverse_rotate(stk_b, value->stack, 1); // rrb
		push_elements(stk_b, stk_a, value->stack, 0); // pa
	}
}
