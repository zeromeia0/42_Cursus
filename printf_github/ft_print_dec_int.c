/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:47:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/22 18:51:11 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec_int_number(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
