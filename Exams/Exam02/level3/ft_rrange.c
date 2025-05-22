/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:22:09 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 14:02:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int *range;
	int	i = 0;
	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end + 1));
	else
		range = (int *)malloc(sizeof(int) *(end - start + 1));
	if (!range)
		return (NULL);
	while (start != end)
	{
		range[i++] = end;
		end -= (start < end) ? 1 : -1;
	}
	range[i] = end;
	return (range);
}

int	main(void)
{
	int *r = ft_rrange(3, 7);
	for (int i = 0; i <= 7 - 3; i++)
		printf("%d ", r[i]);
}