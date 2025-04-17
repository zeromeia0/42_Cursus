/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr_to_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:51:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/17 18:22:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int apply_letter(int nb, int low_or_up, t_hexa *apply)
{
	apply->rem = nb % 16;
	nb /= 16;
	if (apply->rem <= 9)
		apply->buffer[apply->i] = '0' + apply->rem;
	else
		apply->buffer[apply->i] = (low_or_up - 10) + apply->rem;
	apply->i++;
	return (nb);
}

char *decimal_to_hexadecimal(int nb, char base)
{
	t_hexa *var;

	if (nb == 0)
		return (ft_strdup("0"));
	var = malloc(sizeof(t_hexa));
	if (!var)
		return (NULL);
	var->i = 0;
	while (nb != 0)
		nb = apply_letter(nb, base, var);
	var->len = var->i;
	var->result = malloc(var->len + 1);
	if (!var->result)
	{
		free(var);
		return (NULL);
	}
	var->a = 0;
	while (var->len > 0)
	{
		var->len--;
		var->result[var->a++] = var->buffer[var->len];
	}
	var->result[var->a] = '\0';
	free(var);
	return (var->result);
}


/* int	main(void)
{
	char	*hex;

	hex = decimal_to_hexadecimal_lower(1000);
	if (hex)
	{
		ft_putstr_fd(hex, 1);
		ft_putchar_fd('\n', 1);
		free(hex);
	}
	return (0);
} */