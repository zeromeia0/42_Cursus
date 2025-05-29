/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:20:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/28 09:37:19 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0, result = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
void ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int is_prime(int nb)
{
	int i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int final = 0, i = 0, result = 0;
	if (argc == 2)
	{
		final = ft_atoi(argv[1]);
		while (i <= final)
		{
			if (is_prime(i))
			{
				result += i;
			}
			i++;
		}
		ft_putnbr(result);
	}
	write(1, "\n", 1);
	return (0);
}