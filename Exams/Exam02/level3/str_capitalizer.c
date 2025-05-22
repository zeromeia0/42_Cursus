/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:39:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 13:28:36 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}
int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}
void	str_capitalizer(char *str)
{
	int		i;

	i = 0;
	if (is_lower(str[i]))
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (is_upper(str[i]))
			str[i] += 32;
		if (is_lower(str[i]) && (str[i - 1] == ' ' || str[i] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int		main(int argc, char *argv[])
{
	int		i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			i ++;
		}
	}
	write(1, "\n", 1);
	return (0);
}