/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:15:03 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/01 16:16:53 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char a = 'a';
	printf("MY function: %d\nOriginal: %d\n", ft_tolower(a), tolower(a));
	return (0);
}*/
