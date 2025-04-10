/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:27:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/10 21:33:39 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dsize <= dst_len)
		return (dsize + ft_strlen(src));
	while (src[i] && j + i < dsize)
	{
		dst[j] = src[i];
		i++;
	}
	dst[j] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "FeLIZ";
	char dest[50];
	size_t dsize = sizeof(str);
	printf("My function: %ld\n", ft_strlcat(dest, str, dsize));
	return (0);
}*/
