/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:51:16 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 19:06:24 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0, j = 0;
	char temp;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (j < i)
		{
			temp = argv[1][j];
			argv[1][j] = argv[1][i];
			argv[1][i] = temp;
			i--;
			j++;
		}
		write(1, argv[1], j + i + 1);
	}
	write(1, "\n", 1);
	return (0);
}
