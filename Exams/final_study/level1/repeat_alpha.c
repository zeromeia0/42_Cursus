/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:39:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 18:45:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0, count;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			count = 0;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				count += (argv[1][i] - 'a' + 1);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				count += (argv[1][i] - 'A' + 1);
			else
				count = 1;
			while (count--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}