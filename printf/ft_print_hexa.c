/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:27:30 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/19 22:24:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nb, int lowercase)
{
	char	*str;
	int		count;

	str = NULL;
	if (lowercase == 'a')
		str = decimal_to_hexadecimal(nb, 'a');
	else if (lowercase == 'A')
		str = decimal_to_hexadecimal(nb, 'A');
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
