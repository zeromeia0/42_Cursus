/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:44:59 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 23:06:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
#include <string.h>
int main(void)
{
	char str[] = "adadasdad";
	char dest[3];
	size_t n = sizeof(str);
	printf("My function: %s\n", 
	(char *)ft_memcpy(dest, str, n) //(char *)memcpy(dest, str, n));
	);
	return (0);
}*/
