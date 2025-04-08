/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:10:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/08 21:13:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

int	make_short(char const *s, char c, char **strs, int *i, int *k)
{
	int		start;

	while (s[*k] == c && s[*k])
		(*k)++;
	start = *k;
	while (s[*k] != c && s[*k])
		(*k)++;
	strs[*i] = ft_substr(s, start, *k - start);
	if (!strs[*i])
	{
		strs[*i] = NULL;
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	strs = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[k])
	{
		if (s[k] != c)
			make_short(s, c, strs, &i, &k);
		else
			k++;
	}
	strs[i] = NULL;
	return (strs);
}
/*
#include <stdio.h>
int main(void)
{
    char **str = ft_split("Hello world", ' ');
    int i = 0;

    while (str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }

    return (0);
}*/
