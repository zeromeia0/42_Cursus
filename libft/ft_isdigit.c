/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:34:50 by vvazzs            #+#    #+#             */
/*   Updated: 2025/03/31 16:39:05 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	char	a;

	a = (char)c;
	if (!(a >= '0' && a <= '9'))
		return (0);
	return (1);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char a = '5';
	printf("My function: %d\nOriginal: %d\n", ft_isdigit(a), !!isdigit(a));
	return (0);
}*/
