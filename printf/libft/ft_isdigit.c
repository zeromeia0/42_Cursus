/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:34:50 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 22:44:58 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
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
