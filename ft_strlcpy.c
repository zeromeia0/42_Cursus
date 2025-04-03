/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:19:51 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/01 15:26:25 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "Hello";
	char dest[10];
	size_t n = sizeof(src);
	printf("My function: %ld\nOriginal: %ld\n", 
	ft_strlcpy(dest, src, n), strlcpy(dest, src, n));
	return (0);
}*/
