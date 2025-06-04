/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:03:51 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 13:27:45 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int is_space(char c)
{
	return (c <= 32);
}

int main(int argc, char *argv[])
{
	int len = 0, j, first_word = 0;

	if (argc == 2)
	{
		while (argv[1][len])
			len++;
		len--;
		while (len >= 0)
		{
			while (len >= 0 && is_space(argv[1][len]))
				len--;
			j = len;
			while (j >= 0 && !is_space(argv[1][j]))
				j--;
			if (first_word)
				write(1, " ", 1);
			write(1, &argv[1][j + 1], len - j);
			first_word = 1;
			len = j;
		}
	}
	return (write(1, "\n", 1), 0);
}
