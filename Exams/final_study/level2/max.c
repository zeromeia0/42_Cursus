/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:16:12 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 21:21:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int max = tab[0];
	unsigned int i = 0;
	while (i < len)
	{
		if (max < tab[i + 1])
			max = tab[i + 1];
		i++;
	}
	return (max);
}

int main(void)
{
	int tab[] = {1, 5, -3};
	int len = 2;
	printf("%d\n", max(tab, len));
	return (0);
}