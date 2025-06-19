/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lixo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:24:37 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/19 17:24:55 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_last_digit(int argc, char *argv[], t_base_value *value)
{
	int i = -1;
	long *array = copy_array(value);
	char *binary_str;

	(void)argc;
	(void)argv;
	index_it(value);
	while (++i < value->stack->stack_a_length)
	{
		binary_str = to_binary_string(value->stack->stack_a[i]);
		array[i] = ft_atol(binary_str); // This will now convert the binary string to a long
		printf("%ld ", array[i]);
	}
}