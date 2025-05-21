/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:38:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 08:01:48 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	atoi(char *str)
{
	int result = 0, i = 0;

	while (str[i] && is_number(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void put_hex(int nbr)
{
	char hexa[17] = "0123456789abcdef";

	if (nbr >= 16)
		put_hex(nbr / 16);
	nbr = hexa[nbr % 16];
	write(1, &nbr, 1);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		put_hex(atoi(argv[1]));
	write(1, "\n", 1);
}