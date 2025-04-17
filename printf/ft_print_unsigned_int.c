/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/17 18:49:54 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	unsigned_putnbr_fd(unsigned int n)
{
	char	digit;

	if (n >= 10)
		unsigned_putnbr_fd(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

unsigned int  ft_print_unsigned_int(int nb)
{
	unsigned int unb;

	if (nb < 0)
		unb = max_unsigned + nb + 1;
	else
		unb = nb;
	unsigned_putnbr_fd(unb);
	return (unb);
}

/* int main(void)
{
	int nb = -15;
	convert_to_unsigned(nb);
	printf("\n%u\n", (unsigned int)nb);
	return (0);
} */