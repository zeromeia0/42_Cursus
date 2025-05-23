/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:09:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 23:13:03 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}
int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (is_upper(argv[1][i]))
				argv[1][i] = 'Z' - (argv[1][i] - 'Z');
			else if (is_lower(argv[1][i]))
				argv[1][i] = 'a' + (argv[1][i] - 'z');
			write(1, &argv[1][i++], 1);
		}
	}	
	write(1, "\n", 1);
	return (0);
}