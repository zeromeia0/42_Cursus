/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:36:35 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/08 14:43:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space (char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i] && !is_space(argv[1][i]))
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
