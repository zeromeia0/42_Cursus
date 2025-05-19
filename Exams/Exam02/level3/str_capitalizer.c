/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:39:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 21:48:41 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}
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
	int i = 1, j = 0;
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			while (argv[i][j])
			{
				if (is_upper(argv[i][j]))
					argv[i][j] += 32;
				j++;
			}
			i++;
		} 
	}
	write(1, "\n", 1);
	return (0);
}