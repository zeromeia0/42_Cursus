/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_single_char_conversion.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:04:41 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/16 21:44:38 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	full_str(const char *str)
{
	ft_putstr_fd((char *)str, 1);
	return (0);
}

/* int main(void)
{
	// single_char('b');
	full_str("\0\n");
	return (0);
} */