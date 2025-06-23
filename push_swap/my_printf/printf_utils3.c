/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:13:12 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/23 21:19:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_print_long(long number)
{
	char	*str;
	long	len;

	str = ft_long_itoa(number);
	if (!str)
		return (0);
	len = (write(1, str, ft_strlen(str)));
	free(str);
	return (len);
}
