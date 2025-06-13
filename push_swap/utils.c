/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/13 13:04:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);	
}

long	ft_atol(char *str)
{
	int	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long count_digits(long nb)
{
	long count;
	
	count = 1;
	if (nb >= 0 && nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
