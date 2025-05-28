/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:23:13 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 19:28:10 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcpm(char *s1, char *s2)
{
	int i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
	}
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int main(void)
{
	char str1[] = " sla\0 ";
	char str2[] = " sla ";
	printf("%d\n%d\n", ft_strcpm(str1, str2), strcmp(str1, str2));
	return (0);
}