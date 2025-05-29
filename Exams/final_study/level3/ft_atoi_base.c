/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:45:42 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/29 08:53:26 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int convert(char c, int base)
{
	if (c >= '0' && c >= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int ft_atoi_base(char *str, int str_base)
{
	int i = 0, result = 0, sign = 1, value;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		value = convert(str[i], str_base);
		if (value < 0 || value >= str_base)
			break;
		result = result * sign + value;
		i++;
	}
	return (result * sign);
}

