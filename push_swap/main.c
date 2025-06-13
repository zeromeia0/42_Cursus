/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:50 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/13 13:05:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int i = 1;
	if (argc == 1)
		return (ft_printf("Coloca os argumentos\n"), 0);
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("Digits: %ld\t| Argv[%d]: %ld\n", count_digits(ft_atol(argv[i])), i, ft_atol(argv[i]));
			i++;
		}
	}
	return (0);
}