/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:47:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/17 20:02:43 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec_int_number(int nb)
{
	char	*str;

	str = ft_itoa(nb);
	ft_putstr_fd(str, 1);
	return (0);
}

/* int main(void)
{
	int nb = 5;
	ft_print_dec_int_number(nb);
	return (0);
} */