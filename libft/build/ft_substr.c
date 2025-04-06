/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:22:52 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/05 15:31:33 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char		*str;
	unsigned int	i;

	while (s[i])
		i++;
	i -= start;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = start;
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
		char str[] = "AFTER ALL THIS TIME";
		unsigned int start = 6;
		size_t len = 15;
		printf("%s\n", ft_substr(str, start, len));
		return (0);
}
