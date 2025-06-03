/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:49:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 15:59:52 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


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
	int i = 0; int count = 0;
	if (argc == 2)
	{
		int nb = ft_atoi(argv[1]);
		while (i <= nb)
		{
			if (is_prime(i))
				count += i;
			i++;
		}
		ft_putnbr(count);
	}
	return (printf("\n"), 0);
}