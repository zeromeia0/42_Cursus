/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:39:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/18 18:14:41 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	char			hex_digits[17];
	char			buffer[16];
	int				i;
	int				count;

	i = 0;
	count = 0;
	ft_strlcpy(hex_digits, "0123456789abcdef", 17);
	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	while (address > 0)
	{
		buffer[i++] = hex_digits[address % 16];
		address /= 16;
	}
	count += write(1, "0x", 2);
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}
