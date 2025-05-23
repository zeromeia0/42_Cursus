/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:43:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 12:49:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int max = 0;
	unsigned int i = 0;
	if (!tab || len == 0)
		return (max);
	while (i < len)
	{
		if (tab[i] >= max)
			max = tab[i];
		i++;
	}
	return (max);
}

/* int main(void)
{
	int tab[] = {0, 321, 432, 56341, 999, 9};
	int len = 5;
	printf("%d\n", max(tab, len));
	return (0);
} */