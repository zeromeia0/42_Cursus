/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:39:14 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 08:42:24 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm = 0;
	if (a == 0 || b == 0)
		return (lcm);
	lcm = (a > b) ? a : b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		unsigned int m = lcm(atoi(argv[1]), atoi(argv[2]));
		printf("LCM: %u\n", m);
	}
}