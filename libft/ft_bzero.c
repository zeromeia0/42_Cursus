/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:40:10 by vvazzs            #+#    #+#             */
/*   Updated: 2025/03/31 17:43:53 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "da minha voz";
	char str2[] = "da minha voz";
	size_t n = 5;

	ft_bzero(&str1[6], n);
	bzero (&str2[6], n);
	printf("My function: %s\nOriginal: %s\n", str1, str2);
	return (0);
}*/
