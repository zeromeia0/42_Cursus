/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:34:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/23 22:11:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	super_duper_hiper_free(void)
{
	t_base_value *valor;

	valor = value();
	if (!valor)
		return;

	if (valor->stack)
	{
		if (valor->stack->stack_a)
		{
			free(valor->stack->stack_a);
			valor->stack->stack_a = NULL;
		}
		if (valor->stack->stack_b)
		{
			free(valor->stack->stack_b);
			valor->stack->stack_b = NULL;
		}
		free(valor->stack);
		valor->stack = NULL;
	}

	free(valor);
}

