/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_number_to_hexa_to_string.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:09:32 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/16 21:45:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_letter(int nb, t_hexa *apply)
{
	apply->rem = nb % 16;
	nb /= 16;
	if (apply->rem <= 9)
		apply->buffer[apply->i] = '0' + apply->rem;
	else
		apply->buffer[apply->i] = ('a' - 10) + apply->rem;
	apply->i++;
	return (nb);
}

char	*decimal_to_hexadecimal_lower(int nb)
{
	t_hexa	*var;

	var = malloc(sizeof(t_hexa));
	if (!var)
		return (NULL);
	var->i = 0;
	while (nb != 0)
		nb = apply_letter(nb, var);
	var->len = var->i;
	var->result = malloc(var->len + 1);
	if (!var->result)
		return (NULL);
	var->a = 0;
	while (var->len > 0)
	{
		var->len--;
		var->result[var->a] = var->buffer[var->len];
		var->a++;
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
