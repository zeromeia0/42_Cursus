/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:04:55 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/08 19:07:53 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	putnbr_fake(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*str;
	int		num;

	num = n;
	digits = putnbr_fake(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	(str = (char *)malloc(digits + 1));
	if (!str)
		return (NULL);
	*(str + digits) = 0;
	while (digits--)
	{
		*(str + digits) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	int n = 54654;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
