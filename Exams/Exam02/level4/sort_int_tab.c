/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:31:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/26 19:59:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <stdio.h>

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0, j;
	int tmp;

	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

  int main(void)
  {
	int tab[] = {999, 2, 143, 1, 1, 323};
	unsigned int size = 6;
	ft_sort_int_tab(tab, size);
	for (unsigned int j = 0; j < size; j++)
		printf("%d ", tab[j]);
	return (0);
  }