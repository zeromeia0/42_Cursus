/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:39:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/17 18:45:35 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	char			hex_digits[] = "0123456789abcdef";
	char			buffer[16];
	int				i;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return;
	}

	address = (unsigned long)ptr;
	while (address > 0)
	{
		buffer[i++] = hex_digits[address % 16];
		address /= 16;
	}

	ft_putstr_fd("0x", 1);
	while (--i >= 0)
		write(1, &buffer[i], 1);
}

/* int main(void)
{
	int nb = 5;
	int *ptr = &nb;
	print_pointer(ptr);
	printf("\n%p\n", ptr);
	return (0);
} */
