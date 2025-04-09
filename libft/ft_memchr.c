/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:24:53 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/05 11:39:11 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		character;

	i = 0;
	str = (const unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == character)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "Hello people";
	char c = 'p';
	size_t a = sizeof(str);
	printf("MY function: %s\nOriginal: %s\n",
		(char *)ft_memchr(str, c, a), (char *)memchr(str, c, a));
	return (0);
}*/
