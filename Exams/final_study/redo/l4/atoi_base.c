/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:44:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/05 08:53:59 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

int base(char c, int base)
{
	int i = 0;
	while (c >= '0' && c <= '9')
		return (c - '0');
	while (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	while (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
}

int atoi_base(char *str, int str_base)
{
	int i = 0, result = 0, sign = 1, convert;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		convert = base(str[i], str_base);
		if (convert < 0 || convert >= str_base)
			break ;
		result = result * sign + convert;
		i++;
	}
	return (result * sign);
	
}