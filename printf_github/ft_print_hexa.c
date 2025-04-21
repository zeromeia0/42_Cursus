/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:27:30 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/21 21:04:43 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_low_hexa(unsigned int num)
{
	t_hexa	*v;

	v = malloc(sizeof(t_hexa));
	if (!v)
		return (-1);
	v->i = 0;
	v->count = 0;
	ft_strlcpy(v->hexa_index, HEXA_LOWER_STR, 17);
	v->convert_hexa = num;
	while (v->convert_hexa > 0)
	{
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
		v->convert_hexa /= 16;
	}
	while (v->i >= 0)
		v->count += write(1, &v->buffer2[v->i--], 1);
	return (v->count);
}

int	ft_up_hexa(unsigned int num)
{
	t_hexa	*v;

	v = malloc(sizeof(t_hexa));
	if (!v)
		return (-1);
	v->i = 0;
	v->count = 0;
	ft_strlcpy(v->hexa_index, HEXA_UPPER_STR, 17);
	v->convert_hexa = num;
	while (v->convert_hexa > 0)
	{
		v->buffer2[v->i++] = v->hexa_index[v->convert_hexa % 16];
		v->convert_hexa /= 16;
	}
	while (v->i >= 0)
		v->count += write(1, &v->buffer2[v->i--], 1);
	return (v->count);
}
