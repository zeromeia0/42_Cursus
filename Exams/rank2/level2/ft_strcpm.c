/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:48:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 10:02:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
	{
		int i = 0;
		while ((s1[i] || s2[i]) && s1[i] == s2[i])
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}

int main(void)
{
	char str[] = "Salve";
	char str1[] = "salvE";
	printf("%d\n%d\n", ft_strcmp(str, str1), strcmp(str, str1));
	return (0);
}