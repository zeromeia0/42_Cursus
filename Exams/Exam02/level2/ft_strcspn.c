/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:21:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/15 21:25:18 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i = 0, j;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(void)
{
	const char s[] = "";
	const char rej[] = "dsada";
	printf("%zu\n%zu\n", ft_strcspn(s, rej), strcspn(s, rej));
	return (0);
}