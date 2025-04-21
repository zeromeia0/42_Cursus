/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:18:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/21 21:05:17 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_unsigned_int(int nb)
{
	unsigned int	unb;
	unsigned int	count;
	int				digit;

	count = 0;
	if (nb < 0)
		unb = MAX_UNSIGNED + nb + 1;
	else
		unb = nb;
	if (unb >= 10)
		count += ft_print_unsigned_int(unb / 10);
	digit = (unb % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}
