/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:50:14 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 22:13:52 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_strcat(char *dest, const char *src, int start)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final_str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!final_str)
		return (NULL);
	my_strcat(final_str, s1, 0);
	my_strcat(final_str, s2, i);
	final_str[i + j] = '\0';
	return (final_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "Hello ";
	char dest[] = "World :)";
	printf("%s\n", ft_strjoin(str, dest));
	return (0);
}*/
