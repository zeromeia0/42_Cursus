/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:27:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/14 15:12:35 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dsize == 0)
		return (src_len);
	if (dest_len >= dsize)
		return (dsize + src_len);
	while (src[i] && dest_len + i < dsize -1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	//char str[] = "FeLIZ";
	char dest[50];
	//size_t dsize = sizeof(str);
	printf("My function: %ld\n", ft_strlcat(dest, "lorem", 15));
	return (0);
}*/