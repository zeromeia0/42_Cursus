/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:40:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 14:47:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>>

int count_len(int nbr)
{
	int i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
char *ft_itoa(int nbr)
{
	int len = count_len(nbr);
	char *str;
	
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	int i = len - 1;
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
	}
	 while (nbr >= 10)
	 {
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	 }
	 str[i] = nbr + '0';
	 return str);
	 
		
}