/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:03:33 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/10 21:35:10 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (str[i] && i < n)
	{
		str[i] = character;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.
int main(void)
{
	char str[] = "hellow world! :)";
	char c = 'K';
	size_t n = 5;
	printf("MY function: %s\nOriginal: %s\n", 
	(char *)ft_memset(str, c, n), (char *)memset(str, c, n));
	return (0);
}*/
