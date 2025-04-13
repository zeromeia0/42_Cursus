/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:10 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 22:43:58 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char a = ' ';
	printf("My function: %d\nOriginal: %d\n", ft_isalpha(a), !!isalpha(a));
	return (0);
}*/
