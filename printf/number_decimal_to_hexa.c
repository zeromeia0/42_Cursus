/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_decimal_to_hexa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:27:30 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/16 21:50:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int decimal_to_hexa(int nb)
{
    char *str;
    str = decimal_to_hexadecimal_lower(nb);
    if (str)
    {
        char *copy = malloc(strlen(str) + 1);
		if (copy)
        {
            ft_strlcpy(copy, str, strlen(str) + 1);
            ft_putstr_fd(copy, 1);
            ft_putchar_fd('\n', 1);
            free(copy);
        }
        free(str);
    }
    return (0);
}

int main(void)
{
	int nb = 0;
	decimal_to_hexa(nb);
	return (0);
}