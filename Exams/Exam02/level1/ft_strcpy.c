/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:01:02 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/08 15:06:28 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int i = -1;
	while (s2[i++])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int main(void)
{
	char s1[50];
	char s2[] = "Salve";
	printf("%s", ft_strcpy(s1, s2));
	printf("\n%s", strcpy(s1, s2));
	return (0);
}
