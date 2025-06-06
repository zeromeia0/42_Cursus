/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:33:57 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/05 08:42:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count_digits(int nb)
{
	int i = 0;
	if (nb < 0)
		i++;
	while (nb > 10 || nb < -10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nb)
{
	long number = nb;
	int digits = count_digits(nb);
	char *str = malloc(sizeof(char *) * digits + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (digits >= 0 && str[digits] != '-')
	{
		str[digits] = '0' + (number % 10);
		number /= 10;
		digits--;
	}
	return (str);
}

int main(void)
{
	int nb = 214748374;
	return (printf("%s\n", ft_itoa(nb)), 0);
}