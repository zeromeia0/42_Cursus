/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:57:19 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 13:06:21 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	octet = ((octet & 0xF0) >> 4) | ((octet & 0x0F) << 4);
	octet = ((octet & 0xCC) >> 2) | ((octet & 0x33) << 2);
	octet = ((octet & 0xAA) >> 1) | ((octet & 0x55) << 1);
	return octet;
}
