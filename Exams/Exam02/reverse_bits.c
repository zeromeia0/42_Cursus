/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:09:35 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/22 16:15:10 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char   reverse_bits(unsigned char octet)
{
	octet = ((octet & 0b11110000) >> 4 | (octet & 0b00001111) << 4);
	octet = ((octet & 0b11001100) >> 2 | (octet & 0b00110011) << 2);
	octet = ((octet & 0b10101010) >> 1 | (octet & 0b01010101) << 1);
	return (octet);
}
