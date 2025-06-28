/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:34:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 14:59:42 by vivaz-ca         ###   ########.fr       */
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
		free(valor->stack);
		valor->stack = NULL;
	}
	if (valor->splited)
		free_split(valor->splited);
	exit(0);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
