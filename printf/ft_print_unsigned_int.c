/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/18 17:32:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_putnbr_fd(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 10)
		count += unsigned_putnbr_fd(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

unsigned int	ft_print_unsigned_int(int nb)
{
	unsigned int	unb;

	if (nb < 0)
		unb = MAX_UNSIGNED + nb + 1;
	else
		unb = nb;
	return (unsigned_putnbr_fd(unb));
}
