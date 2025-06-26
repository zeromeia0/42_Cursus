/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:34:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/26 15:16:45 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	super_duper_hiper_free(int chama)
{
	t_base_value	*valor;

	(void)chama;
	valor = value();
	if (!valor)
		return ;
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
		if (valor->splited)
			free_split(valor->splited);
		free(valor->stack);
		valor->stack = NULL;
	}
	exit(0);
}
