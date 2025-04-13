/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:24:54 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 15:56:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 || !s2) && n > 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "test\200";
	char s2[] = "test\0";
	size_t n = 6;
	printf("%i", (int) '\200');
	printf("My function: %d\nOriginal: %d\n",
	ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	return (0);	
}
		*/