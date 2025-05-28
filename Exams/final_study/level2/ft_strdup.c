/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:34:23 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/27 20:42:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(char *str)
{
	if (!str[0])
		return (NULL);
	char *dest;
	int i = 0;
	while (str[i])
		i++;
	dest = malloc(sizeof(char *) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

/* int main(void)
{
	char str[] = "";
	char *dup = ft_strdup(str);
	if (dup)
		printf("%s\n", dup);
	else
		printf("NULL\n");
	free(dup);
	return (0);
} */