/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:32:20 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/16 22:04:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_printf(const char *str)
{
	ft_putstr_fd((char*)str, 1);
	return (1);	
} */

int main(void)
{	
	int nb = 5;
	int *ptr = &nb;
	printf("Ptr = %p\n", ptr);
	return (0);
}