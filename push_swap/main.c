/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:28:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 14:31:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_base_value *valor = value();
	if (argc < 2)
		return (0);
	
	valor->stack = malloc(sizeof(t_stack));
	if (!valor->stack)
		return (1);
	if (argc == 2)
	{
		if (!sentence(argc, argv, valor))
			return (free(valor->stack), 1);
		if (!parsing(valor->stack->stack_a_length, valor->splited, valor))
			return (super_duper_hiper_free(1), 1);
	}
	else if (argc > 2)
	{
		valor->stack->stack_a_length = argc - 1;
		valor->stack->stack_b_length = 0;
	
		valor->stack->stack_a = malloc(sizeof(long) * (argc - 1));
		if (!valor->stack->stack_a)
			return (free(valor->stack), 1);
		valor->stack->stack_b = malloc(sizeof(long) * (argc - 1));
		if (!valor->stack->stack_b)
			return (free(valor->stack->stack_a), free(valor->stack), 1);
		for (int i = 0; i < argc - 1; i++)
			valor->stack->stack_a[i] = ft_atol(argv[i + 1]);
		if (!index_it(valor))
			return (0);
		if (!parsing(argc, argv, valor))
			return (0);
		long max = valor->stack->stack_a_length - 1;
		int max_digits = 0;
		while ((max >> max_digits) != 0)
			max_digits++;
		valor->max_digits = max_digits;
		if (valor->stack->stack_a_length == 3)
			{
				sort_three(valor);
				return (super_duper_hiper_free(0), 0);
			}
		else if (valor->stack->stack_a_length == 5)
			sort_five(valor);
		else
			radix_sort(valor);
		}
	// print_stack("Final stack: ", valor->stack->stack_a, valor->stack->stack_a_length);
	super_duper_hiper_free(0);
	return (0);
}
