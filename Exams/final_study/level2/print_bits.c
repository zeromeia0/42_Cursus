/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:21:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 21:24:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bits;
	while (i--)
	{
		bits = ((octet >> i) & 1) + '0';
		write(1, &bits, 1);
	}
}

#include <stdio.h>

int main(void)
{
	unsigned char octet = 3;
	print_bits(octet);
	printf("\n");
	return (0);
}