/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:38:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/28 15:40:21 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_digits_loser(long nb)
{
	long	count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

long	count_digits(long nb)
{
	long	count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	get_most_digits(int argc, t_base_value *value, long *max_digits)
{
	int		i;
	long	digits;

	i = 0;
	*max_digits = count_digits(value->stack->stack_a[i]);
	while (++i < argc - 1)
	{
		digits = count_digits(value->stack->stack_a[i]);
		if (*max_digits < digits)
			*max_digits = digits;
	}
	return ((int)(*max_digits));
}
