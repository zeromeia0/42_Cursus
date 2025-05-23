/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:03:09 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 12:14:36 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


char *ft_strrev(char *str)
{
	int i = 0, j = 0;
	char temp;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int main(void)
{
	char str[] = "salve";
	printf("%s\n", ft_strrev(str));
	return (0);
}
