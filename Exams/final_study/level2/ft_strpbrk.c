/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:42:25 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 20:54:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0, j;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	const char s1[] = "42 Network";
	const char s2[] = "asdadd4";
	char *res = ft_strpbrk(s1, s2);
	if (!res)
		printf("NULL");
	else
		printf("%s\n", res /* strpbrk(s1, s2) */);
	return (0);
}