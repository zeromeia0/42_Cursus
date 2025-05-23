/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:55:23 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 22:59:13 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc == 4 && argv[2][0] && !argv[2][1] && argv[3][0] && !argv[3][1])
	{
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
			{
				write(1, &argv[3][0], 1);
				i++;
			}
			else
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}