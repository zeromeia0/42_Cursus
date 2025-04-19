/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr_to_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:51:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/19 22:58:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_letter(unsigned int num, int low_or_up, t_hexa *apply)
{
	int	rem;

	rem = num % 16;
	num /= 16;
	if (rem <= 9)
		apply->buffer[apply->i] = '0' + rem;
	else
		apply->buffer[apply->i] = (low_or_up - 10) + rem;
	apply->i++;
	apply->len++;
	return (num);
}

char	*decimal_to_hexadecimal(unsigned int nb, char base)
{
	t_hexa	*var;

	if (nb == 0)
		return (ft_strdup("0"));
	var = malloc(sizeof(t_hexa));
	if (!var)
		return (NULL);
	var->i = 0;
	var->len = 0;
	while (nb != 0)
		nb = apply_letter(nb, base, var);
	var->result = malloc(var->len + 1);
	if (!var->result)
	{
		free(var);
		return (NULL);
	}
	var->a = 0;
	while (var->len-- > 0)
		var->result[var->a++] = var->buffer[var->len];
	var->result[var->a] = '\0';
	return (var->result);
	free(var);
}
