/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:51:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 11:01:37 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
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
	const char s1[] = "UHUL";
	const char s2[] = "zH";
	printf("%s\n%s\n", ft_strpbrk(s1, s2), strpbrk(s1, s2));
	return (0);
}