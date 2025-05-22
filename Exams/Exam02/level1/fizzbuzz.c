/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:44:24 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 14:39:28 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int nb)
{
	if (nb >= 10)
		ft_putchar(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}
int main(void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
				write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
				write(1, "fizz", 4);
		else if (i % 5 == 0)
				write(1, "buzz", 4);
		else
			ft_putchar(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

