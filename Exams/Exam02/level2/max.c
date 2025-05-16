/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/16 11:03:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int *tab, unsigned int len)
{
	int i = 0, max;
	if (!tab || len == 0)
		return (0);
	max = tab[0];
	while (i < (int)len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4};
	printf("%d", max(tab, 5));
	printf("\n");
	return (0);
}
