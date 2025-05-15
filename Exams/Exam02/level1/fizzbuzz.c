/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:44:24 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/08 14:51:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char str;
	int i = 0;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
				write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
				write(1, "fizz", 4);
		else if (i % 5 == 0)
				write(1, "buzz", 4);
		else
		{
			if (i >= 10)
			{
				str = '0' + (i / 10);
				write(1, &str, 1);
			}
			str = '0' + (i % 10);
			write(1, &str, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
