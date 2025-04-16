/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:14:32 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/16 21:47:06 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct s_hexa
{
	int		i;
	int		rem;
	int		len;
	int		a;
	char	*result;
	char	buffer[20];
}	t_hexa;

int		ft_printf(const char *str);
char	*decimal_to_hexadecimal_lower(int nb);
int 	decimal_to_hexa(int nb);




#endif