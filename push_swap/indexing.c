/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:43:20 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 17:23:35 by vivaz-ca         ###   ########.fr       */
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
		return (0);
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
		return (0);
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
	int		i, j;

	sorted = quick_sort(value);
	copied = copy_array(value);
	i = 0;
	
	if (!sorted || !copied)
		return (free(sorted), free(copied), 0);
	while (i < value->stack->stack_a_length)
	{
		j = 0;
		while (j < value->stack->stack_a_length)
		{
			if (copied[i] == sorted[j])
			{
				copied[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < value->stack->stack_a_length)
	{
		value->stack->stack_a[i] = copied[i];
		i++;
	}
	printf("\n");
	free(sorted);
	free(copied);
	return (1);
}
