/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:48:42 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 14:04:10 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
	return (c <= 32);
}

void rotstring(char *str)
{
	int i = 0, first_word;
	while (str[i] && is_space(str[i]))
		i++;
	first_word = i;
	while (str[i] && !is_space(str[i])) 
		i++;
	while (str[i])
	{
		if (is_space(str[i]))
		{
			while (str[i] && is_space(str[i]))
				i++;
			if (str[i])
				write(1, " ", 1);
		}
		else
			write(1, &str[i++], 1);
	}
	if (i != first_word)
		write(1, " ", 1);
	while (str[first_word] && !is_space(str[first_word]))
		write(1, &str[first_word++], 1);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		rotstring(argv[1]);
	return (write(1, "\n", 1));
}
