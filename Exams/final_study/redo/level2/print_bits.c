/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:42:32 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 15:44:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


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

int main(void)
{
	unsigned  char oc = 5;
	print_bits(oc);
	return (printf("\n"), 0);
}