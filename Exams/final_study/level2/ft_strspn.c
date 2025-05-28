/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:35:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 19:41:33 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0, j, check;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}

int main(void)
{
	const char s[] = "";
	const char acceppt[] = "aqul img                         										e";
	printf("%ld\n%ld\n", ft_strspn(s, acceppt), strspn(s, acceppt));
	return (0);
}