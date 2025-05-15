/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:15:29 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/15 18:15:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int		*rrange;
	int		i;

	if (start > end)
		rrange = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		rrange = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		rrange[i++] = start;
		end -= (start > end) ? -1 : 1;
	}
	rrange[i] = start;
	return (rrange);
}

/* int	main(void)
{
	int	*rrange = ft_rrange(1, 3);
	int	i = 0;
	while (i <= 3 - 1)
	{
		printf("%d ", rrange[i]);
		i++;
	}
	return (0);
} */