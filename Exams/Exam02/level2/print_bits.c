/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:35:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/16 15:18:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}