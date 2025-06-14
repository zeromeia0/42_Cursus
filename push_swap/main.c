/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:50 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/14 17:09:26 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (!parsing(argc, argv))
		return (1);
	value()->stack = malloc(sizeof(t_stack));
	if (!value()->stack)
		return (1);
	value()->stack->stack_a = NULL;
	// print_stuff(argc, argv, value());
	receive_values(argc, argv, &value()->stack->stack_a);
	return (0);
}
