/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:24:54 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/10 21:34:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "salve ada";
	char s2[] = "salve da";
	size_t n = 15;
	printf("My function: %d\nOriginal: %d\n",
			ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	return (0);
}*/
