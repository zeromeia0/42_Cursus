/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:55:20 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/29 09:05:44 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
	int *range, i = 0;
	range = (int *)malloc(sizeof(int) * (start > end) ? (start - end + 1) : (end - start + 1));
}

int *ft_range(int start, int end)
{
	int *range, i = 0;
	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		range = (int*)malloc(sizeof(int) * (end - start) + 1);
	while (start != end)
	{
		range[i++] = start;
		start = (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}

int main(void)
{
	int *range = ft_range(1, 3);
	for (int i = 0; i <= sizeof(range); i++)
		printf("%d", range[i]);
	return (0);
}