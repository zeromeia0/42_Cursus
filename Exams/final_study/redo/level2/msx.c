/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:35:41 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 15:42:19 by vivaz-ca         ###   ########.fr       */
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
	int tab[] = {0, 5, 2, 99, -323};
	printf("%d\n", max(tab, 4));
	return (0);
}