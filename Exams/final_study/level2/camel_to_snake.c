/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:10:57 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 19:13:22 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (is_upper(argv[1][i]))
			{
				write(1, "_", 1);
				argv[1][i] += 32;
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}