/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:10 by vvazzs            #+#    #+#             */
/*   Updated: 2025/03/31 16:34:21 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>

int	ft_isalpha(int c)
{
	char	chr;

	chr = (char)c;
	if (!(chr >= 'a' && chr <= 'z') && !(chr >= 'A' && chr <= 'Z'))
		return (0);
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	char a = ' ';
	printf("My function: %d\nOriginal: %d\n", ft_isalpha(a), !!isalpha(a));
	return (0);
}*/
