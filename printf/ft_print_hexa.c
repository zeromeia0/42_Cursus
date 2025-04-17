/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:27:30 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/17 20:17:25 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hexa(unsigned int nb, int lowercase)
{
	char *str;

	if (lowercase == 'a')
		str = decimal_to_hexadecimal(nb, 'a');
	else if (lowercase == 'A')
		str = decimal_to_hexadecimal(nb, 'A');
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	return (0);
}


/* int main(void)
{
	int nb = 1000;
	decimal_to_hexa(nb);
	return (0);
} */