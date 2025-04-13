/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:41:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/13 15:50:32 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src;
	const unsigned char	*dest;
	size_t				i;

	src = (const unsigned char *)s1;
	dest = (const unsigned char *)s2;
	i = 0;
	if ((!s1 || !s2) && n > 0)
		return (0);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (src[i] != dest[i])
			return (src[i] - dest[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
		char str[] =  "abcdefghij";
		char dest[] = "abcdefgxyz";
		size_t n = 7;
		printf("My function: %d\nOriginal: %d\n",
				ft_memcmp(str, dest, n), memcmp(str, dest, n));
		return (0);
}*/
