/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:01:17 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/16 15:11:52 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0, j = 0, tab[256] = {0};

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (tab[(int)argv[1][i]] == 0)
			{
				tab[(int)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		while (argv[2][j])
		{
			if (tab[(int)argv[2][j]] == 0)
			{
				tab[(int)argv[2][j]] = 1;
				write(1, &argv[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}