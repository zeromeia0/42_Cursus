/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:30:08 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 19:35:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0, j;
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
	const char s[] = "42 network ywioeryqwoiruyqoiNdhalksdjhl";
	const char reject[] = "ASDN";
	printf("%ld\n%ld\n", ft_strcspn(s, reject), strcspn(s, reject));
	return (0);
}