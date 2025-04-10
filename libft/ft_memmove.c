/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:19:20 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/10 21:32:45 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	i = 0;
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (dst == source || n == 0)
		return (dest);
	if (dst > source)
	{
		i = n + 1;
		while (i-- != 0)
			dst[i] = source[i];
	}
	else
	{
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[] = "homem";
	char dest[20];
	size_t j = sizeof(src);
	printf("My function: %s\nOriginal: %s\n", 
	(char *)ft_memmove(dest, src, j), (char *)memmove(dest, src, j));
	return (0);
}*/
