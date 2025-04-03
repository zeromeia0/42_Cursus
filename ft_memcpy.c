/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:44:59 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/01 14:18:55 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void	*restrict dest, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	i = 0;
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "just the 2 of us";
	char dest[50];
	size_t n = sizeof(str);
	printf("My function: %s\nOriginal: %s\n", 
	(char *)ft_memcpy(dest, str, n), (char *)memcpy(dest, str, n));
	return (0);
}*/
