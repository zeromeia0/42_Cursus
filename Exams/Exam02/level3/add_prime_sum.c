/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:51:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 09:03:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
    unsigned int nb;
    
    if (nbr < 0)
		return ;
	if (nbr >= 10)
        ft_putnbr(nbr / 10);
    wrirte(1, &"0123456789"[nbr % 10], 1);
}

int is_prime(int nbr)
{
    if (nbr < 2)
        return (0);
    int i = 2;
    while (i * i <= nbr )
    {
        if (nbr % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi(char *str)
{
    int result = 0, sign = 1, i = 0;
	
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result *= result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && ft_atoi(argv[1]) >= 0)
    {
		int n = ft_atoi(argv[1]);
		int sum = 0;
		while (n > 1)
		{
			if (is_prime(n))
				sum += n;
			n--;
		}
		ft_putnbr(sum);
		ft_putchar('\n');
    }
	write(1, "\n", 1);
	return (0);
}