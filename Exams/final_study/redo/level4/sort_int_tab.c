/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:45 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 18:02:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0, j;
	int temp;
	while (i < size)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main(void)
{
	int tab[] = {1, 7, 22, 324, -312, 32}, len = 5;
	sort_int_tab(tab, len);
	for (int j = 0; j <= len; j++)
		printf("%d ", tab[j]);
}