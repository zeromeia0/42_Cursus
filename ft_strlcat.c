/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:27:22 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/01 16:05:21 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	strlcat(char *restrict dst, const char *restrict src, size_t dsize)
{
	size_t	c;
	size_t	d;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dsize <= dst_len)
		return (dsize + ft_strlen(src));
	while (src[i] && j + i < dsize)
		dst[j++] = src[j++];
	dst[j] = '\0';
	return (dst_len + ft_strlen(src));
}
