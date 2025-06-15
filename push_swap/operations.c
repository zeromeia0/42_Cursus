/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:46:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/15 16:57:59 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	push(long *src, int *src_size, long *dest, int *dest_size)
{
	int	i;

	if (*src_size == 0)
		return ;
	i = *dest_size;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];
	(*dest_size)++;
	i = 0;
	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
}

/* int	main(void)
{
	long	src[] = {2, 3, 5, 7};
	long	dest[256] = {0};
	int	src_size = 3;
	int	dest_size = 0;
	int	i;

	printf("Before push\n");
	for (i = 0; i < src_size; i++)
		printf("Src[%d]: %ld\n", i, src[i]);
	printf("Dest[0]: %ld	\n", dest[0]);
	push(src, &src_size, dest, &dest_size);
	printf("\nAfter push:\n");
	for (i = 0; i < src_size; i++)
		printf("Src[%d]: %ld\n", i, src[i]);
	for (i = 0; i < dest_size; i++)
		printf("Dest[%d]: %ld\n", i, dest[i]);
	return (0);
} */
