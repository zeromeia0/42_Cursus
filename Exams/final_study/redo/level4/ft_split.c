/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:40:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_space(char c)
{
	return (c <= 32);
}
char **ft_split(char *str)
{
	char **res;
	int i = 0, j = 0, k = 0, world_count = 0;
	while (str[i])
	{
		if (str[i] > 32 && (i == 0 || is_space(str[i - 1])))
			world_count++;
		i++;
	}
	res = malloc(sizeof(char *) * (world_count + 1));
	if (!res)
		return NULL;
	i = 0;
	while (str[i] && j < world_count)
	{
		while (str[i] && is_space(str[i]))
			i++;
		k = i;
		while (str[i] && str[i] > 32)
			i++;
		res[j] = malloc(i - k + 1);
		if (!res[j])
			return NULL;
		for (int x = 0; x < i - k; x++)
			res[j][x] = str[k + x];
		res[j][i - k] = '\0';
		j++;
	}
	res[j] = NULL;
	return res;
}

 
/* #include <stdio.h>

int main()
{
	char **words = ft_split("Hello  world this is 42");
	for (int i = 0; words[i]; i++)
		printf("word[%d]: %str\n", i, words[i]);
}
 */