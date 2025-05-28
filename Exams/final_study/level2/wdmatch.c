/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:29:23 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/28 09:20:06 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0, j = 0, k = 0;
	if (argc == 3)
	{
		while (argv[1][i])
			i++;
		while (j < i && argv[2][k])
		{
			if (argv[1][j] == argv[2][k])
				j++;
			k++;
		}
		if (j == i)
			write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
