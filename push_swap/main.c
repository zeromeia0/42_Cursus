/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:28:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:51:58 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_single_arg(t_base_value *valor)
{
	if (!parsing(valor->stack->stack_a_length,
			valor->splited, valor))
		return (1);
	return (0);
}

int	init_multi_args_stack(int argc, t_base_value *valor)
{
	valor->stack->stack_a_length = argc - 1;
	valor->stack->stack_b_length = 0;
	valor->stack->stack_a = malloc(sizeof(long) * (argc - 1));
	if (!valor->stack->stack_a)
		return (1);
	valor->stack->stack_b = malloc(sizeof(long) * (argc - 1));
	if (!valor->stack->stack_b)
		return (1);
	return (0);
}

int	fill_stack_values(int argc, char *argv[], t_base_value *valor)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		valor->stack->stack_a[i] = ft_atol(argv[i + 1]);
		i++;
	}
	if (!index_it(valor))
		return (0);
	if (!parsing(argc, argv, valor))
		return (0);
	return (1);
}

int	handle_multiple_args(int argc, char *argv[], t_base_value *valor)
{
	if (init_multi_args_stack(argc, valor))
		return (1);
	if (!fill_stack_values(argc, argv, valor))
		return (0);
	valor->max_digits = calculate_max_digits(
			valor->stack->stack_a_length - 1);
	if (valor->stack->stack_a_length == 3)
	{
		sort_three(valor);
		return (0);
	}
	else if (valor->stack->stack_a_length == 5)
		sort_five(valor);
	else
		radix_sort(valor);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_base_value	*valor;

	valor = value();
	if (argc < 2)
		return (0);
	valor->stack = malloc(sizeof(t_stack));
	if (!valor->stack)
		return (1);
	if (argc == 2)
	{
		if (!sentence(argc, argv, valor))
			return (free(valor->stack), 1);
		if (handle_single_arg(valor))
			return (super_duper_hiper_free(1), 1);
	}
	else if (argc > 2)
		if (handle_multiple_args(argc, argv, valor))
			return (1);
	super_duper_hiper_free(0);
	return (0);
}
