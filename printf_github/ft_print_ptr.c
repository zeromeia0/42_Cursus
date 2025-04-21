/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:39:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/21 21:05:02 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	t_hexa	*var;

	var = malloc(sizeof(t_hexa));
	if (!var)
		return (-1);
	if (!ptr)
		return (write(1, NIL_STR, 5));
	var->i = 0;
	var->count = 0;
	ft_strlcpy(var->hexa_index, HEXA_LOWER_STR, 17);
	var->address = (unsigned long)ptr;
	while (var->address > 0)
	{
		var->buffer2[var->i++] = var->hexa_index[var->address % 16];
		var->address /= 16;
	}
	var->count += write(1, "0x", 2);
	while (--var->i >= 0)
		var->count += write(1, &var->buffer2[var->i], 1);
	return (var->count);
}
