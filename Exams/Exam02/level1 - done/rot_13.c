/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:45:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 22:50:57 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
				argv[1][i] += 13;
			else if ((argv[1][i] >= 'n' && argv[1][i] <='z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
				argv[1][i] -= 13;
			write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}