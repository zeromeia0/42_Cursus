/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:03:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 16:07:56 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *range, i = 0;
	range = malloc(sizeof(int) * ((start > end) ? (start - end) : (end - start)));
	if (!range)
		return (0);
	while(start != end)
	{
		range[i++] = start;
		start += (start > end) ? -1 : 1; 
	}
	range[i] = start;
	return (range);
}

int main(void)
{
	int *range = ft_range(1, 3);
	for (int i = 0; i <= 2; i++)
			printf("%d\n", range[i]);
	return (0);
}