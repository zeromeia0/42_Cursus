/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:03:33 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 22:29:52 by vivaz-ca         ###   ########.fr       */
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
	while (i < n)
	{
		str[i] = character;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "";
	char c = '\0';
	size_t n = sizeof(str);
	printf("MY function: %s\nOriginal: %s\n", 
	(char *)ft_memset(str, c, n), (char *)memset(str, c, n));
	return (0);
}*/
