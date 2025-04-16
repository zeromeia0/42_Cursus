/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:22:13 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 11:29:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "salve";
	char a = 'v';
	printf("My function: %s\nOriginal: %s\n", 
	ft_strchr(str, a), strchr(str, a));
	return (0);
}*/
