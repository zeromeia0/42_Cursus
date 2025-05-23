/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:06:59 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 10:29:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t ft_strspn(const char *s, const char *accept)
{
	int i = 0, j;
	while (s[i])
	{
		for (j = 0; accept[j] && s[i] != accept[j]; j++);
		if (!accept[j])
			break ;
		i++;
	}
	return (i);
}
int main(void)
{
	const char s[] = "Skill issue";
	const char accept[] = "l";
	printf("%ld\n%ld\n", ft_strspn(s, accept), strspn(s, accept));
	return (0);
}