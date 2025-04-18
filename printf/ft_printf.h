/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:14:32 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/18 17:46:06 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define MAX_UNSIGNED 4294967295

typedef struct s_hexa
{
	int				i;
	int				rem;
	int				len;
	int				a;
	char			*result;
	char			buffer[20];
	unsigned int	num_to_unsigned;
}	t_hexa;

char			*decimal_to_hexadecimal(unsigned int nb, char base);
int				ft_print_char(int c);
int				ft_print_dec_int_number(int nb);
int				ft_print_hexa(int nb, int lowercase);
int				ft_print_ptr(void *ptr);
int				ft_print_str(const char *str);
unsigned int	ft_print_unsigned_int(int nb);
int				ft_printf(const char *format, ...);

#endif