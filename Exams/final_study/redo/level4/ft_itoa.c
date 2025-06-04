/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:04:33 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 14:14:13 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count_len(int nb)
{
	int i = 0;
	if (nb < 0)
		i++;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long number = nbr;
	int len = count_len(nbr);
	char *str = (char *)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (len >= 0 && str[len] != '-')
	{
		str[len] = '0' + (number % 10);
		number /= 10;
		len--;
	}
	return (str);
}

int main(void)
{
	int nbr = 214748364;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}