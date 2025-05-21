/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgdc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:28:03 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 08:37:59 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int a = atoi(argv[1]), b = atoi(argv[2]), max = (a > b) ? a : b;
		while (max > 0)
		{
			if (a % max == 0 && b % max == 0)
			{
				printf("%d", max);
				break ;
			}
			max--;
		}
	}
	printf("\n");
	return (0);
}