/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:08:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 16:11:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nb)
{
	if (nb >= 16)
		ft_putnbr(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int ft_atoi(char *str)
{
	int i = 0, result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int nb = ft_atoi(argv[1]);
		ft_putnbr(nb);
	}
	return (write(1, "\n", 1), 0);
	
}