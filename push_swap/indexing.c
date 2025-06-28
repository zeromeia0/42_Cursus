/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:43:20 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 14:59:19 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*copy_array(t_base_value *value)
{
	int		i;
	long	*copy;

	i = 0;
	copy = malloc(sizeof(long) * value->stack->stack_a_length);
	if (!copy)
		return (super_duper_hiper_free(1), NULL);
	while (i < value->stack->stack_a_length)
	{
		copy[i] = value->stack->stack_a[i];
		i++;
	}
	return (copy);
}

long	*quick_sort(t_base_value *value)
{
	long	*sorted;
	int		i;
	long	temp;

	sorted = copy_array(value);
	i = 0;
	if (!sorted)
		return (free(sorted), super_duper_hiper_free(1), NULL);
	while (i < value->stack->stack_a_length - 1)
	{
		if (sorted[i] > sorted[i + 1])
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (sorted);
}

int	index_it(t_base_value *value)
{
	long	*sorted;
	long	*copied;

	sorted = quick_sort(value);
	copied = copy_array(value);
	if (!sorted || !copied)
		return (free(sorted), free(copied), super_duper_hiper_free(1), 0);
	value->i = -1;
	while (++value->i < value->stack->stack_a_length)
	{
		value->j = 0;
		while (value->j < value->stack->stack_a_length)
		{
			if (copied[value->i] == sorted[value->j])
			{
				copied[value->i] = value->j;
				break ;
			}
			value->j++;
		}
	}
	value->i = -1;
	while (++value->i < value->stack->stack_a_length)
		value->stack->stack_a[value->i] = copied[value->i];
	return (free(sorted), free(copied), 1);
}
