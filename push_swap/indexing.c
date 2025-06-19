/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:43:20 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 12:31:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* int main(int argc, char *argv[])
{
	int *max_digits;
	
	get_most_digits(argc, argv, max_digits);
	// FUNCAO RECURSIVA PRA VER QUAL O MAIOR DIGITO?
	// ARRAY[MAX_DIGIT] 6546546 15 999 015	
} */

long *copy_array(t_base_value *value)
{
	int i = 0;
	long *copy = malloc(sizeof(long) * value->stack->stack_a_length);
	if (!copy)
		return (0);
	while (i < value->stack->stack_a_length)
	{
		copy[i] = value->stack->stack_a[i];
		i++;
	}
	return (copy);
}

long *quick_sort(t_base_value *value)
{
	long *sorted = copy_array(value);
	int i = 0;
	if (!sorted)
		return (0);
	while (i < value->stack->stack_a_length - 1)
	{
		if (sorted[i] > sorted[i + 1])
		{
			long temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (sorted);
}

int index_it(t_base_value *value)
{
	long *sorted = quick_sort(value);
	long *copied = copy_array(value);
	int i = 0, j;

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
				break;
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



/* int main(int argc, char *argv[])
{
	t_base_value *value;

	value = malloc(sizeof(t_base_value));
	if (!value)
		return (1);
	value->stack = malloc(sizeof(t_stack));
	if (!value->stack)
		return (1);

	print_stuff(argc, argv, value);
	return (0);
} */
