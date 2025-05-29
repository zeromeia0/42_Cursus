/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:48:35 by jeslin-tici       #+#    #+#             */
/*   Updated: 2025/05/29 09:56:06 by jeslin-tici      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm = 1;
	lcm += (a > b) ? a : b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
	return (lcm);
}

int main(void)
{
	printf("%u\n", lcm(3, 4));
	return (0);
}