/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:39:27 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/14 18:49:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_isalnum(int c)
{
	char	a;

	a = (char)c;
	if (!(is_num(a) || is_lower(a) || is_upper(a)))
		return (0);
	return (8);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char a = 'a';
	printf("My function: %d\nOriginal: %d\n", ft_isalnum(a), !!isalnum(a));
	return (0);
}*/
