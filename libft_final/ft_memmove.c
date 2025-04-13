/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:19:20 by vvazzs            #+#    #+#             */
/*   Updated: 2025/04/13 16:12:39 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_short	mt;

	mt.z = 0;
	mt.dst = (unsigned char *)dest;
	mt.source = (const unsigned char *)src;
	if (mt.dst == mt.source || n == 0)
		return (dest);
	if ((!mt.dst || !src) && n > 0)
		return (NULL);
	if (mt.dst > mt.source)
	{
		mt.z = n;
		while (mt.z-- != 0)
			mt.dst[mt.z] = mt.source[mt.z];
	}
	else
	{
		while (mt.z < n)
		{
			mt.dst[mt.z] = mt.source[mt.z];
			mt.z++;
		}
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void print_result(const char *desc, int passed)
{
	printf("%-40s : %s\n", desc, passed ? "✅" : "❌");
}

int main(void)
{
	char buffer1[100];
	char buffer2[100];

	// 1. Normal copy
	strcpy(buffer1, "Hello World");
	strcpy(buffer2, "AAAAAAAAAAA");
	ft_memmove(buffer2, buffer1, strlen(buffer1) + 1);
	print_result("Normal copy", strcmp(buffer2, "Hello World") == 0);

	// 2. Zero-length copy (should do nothing)
	strcpy(buffer1, "Hello");
	strcpy(buffer2, "World");
	ft_memmove(buffer2, buffer1, 0);
	print_result("Zero-length copy", strcmp(buffer2, "World") == 0);

	// 3. dest == src (should do nothing)
	strcpy(buffer1, "Same location");
	ft_memmove(buffer1, buffer1, strlen(buffer1));
	print_result("Same src and dest", strcmp(buffer1, "Same location") == 0);

	// 4. Overlapping: forward copy
	strcpy(buffer1, "1234567890");
	ft_memmove(buffer1 + 2, buffer1, 8);
	print_result("Overlap forward", strcmp(buffer1, "1212345678") == 0);

	// 5. Overlapping: backward copy
	strcpy(buffer1, "abcdefghij");
	ft_memmove(buffer1, buffer1 + 2, 8);
	print_result("Overlap backward", strcmp(buffer1, "cdefghijij") == 0);

	// 6. NULL src and n == 0
	ft_memmove(buffer1, NULL, 0);
	print_result("NULL src with n == 0", 1);  // should not crash

	// 7. NULL dest and n == 0
	ft_memmove(NULL, buffer1, 0);
	print_result("NULL dest with n == 0", 1);  // should not crash

	// 8. NULL src with n > 0
	void *ret1 = ft_memmove(buffer1, NULL, 5);
	print_result("NULL src with n > 0", ret1 == NULL);

	// 9. NULL dest with n > 0
	void *ret2 = ft_memmove(NULL, buffer1, 5);
	print_result("NULL dest with n > 0", ret2 == NULL);

	// 10. Both NULL with n > 0
	void *ret3 = ft_memmove(NULL, NULL, 5);
	print_result("Both NULL with n > 0", ret3 == NULL);

	// 11. Both NULL with n == 0 (should do nothing)
	ft_memmove(NULL, NULL, 0);
	print_result("Both NULL with n == 0", 1);  // should not crash

	return 0;
}
*/