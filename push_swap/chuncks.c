/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chuncks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:03:27 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/21 18:16:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int len)
{
	if (len <= 100)
		return (len / 5);
	return (len / 11);
}

void	sort_using_chunks(long *a, long *b, t_base_value *value)
{
	int		count = value->stack->stack_a_length;
	int		chunk_size = get_chunk_size(count);
	long	*sorted = malloc(sizeof(long) * count);
	int		i, j, chunk_end;

	for (i = 0; i < count; i++)
		sorted[i] = a[i];
	sort_long_array(sorted, count);
	i = 0;
	while (i < count)
	{
		chunk_end = i + chunk_size;
		while (value->stack->stack_a_length > 0 && i < chunk_end && i < count)
		{
			j = 0;
			while (j < value->stack->stack_a_length)
			{
				if (a[j] >= sorted[i] && a[j] <= sorted[chunk_end - 1])
				{
					if (j <= value->stack->stack_a_length / 2)
						while (j-- > 0)
							single_rotate(a, value->stack, 0); // ra
					else
						while (j++ < value->stack->stack_a_length)
							reverse_rotate(a, value->stack, 0); // rra

					push_elements(a, b, value->stack, 1); // pb
					break ;
				}
				j++;
			}
		}
		i = chunk_end;
	}
	while (value->stack->stack_b_length > 0)
	{
		int max_i = find_max_index(b, value->stack->stack_b_length);
		if (max_i <= value->stack->stack_b_length / 2)
			while (max_i-- > 0)
				single_rotate(b, value->stack, 1); // rb
		else
			while (max_i++ < value->stack->stack_b_length)
				reverse_rotate(b, value->stack, 1); // rrb
		push_elements(b, a, value->stack, 0); // pa
	}
}

