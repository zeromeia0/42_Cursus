/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goated_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:44:26 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/24 16:51:00 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	if (!*s)
		return (0);
	while (*s == c)
		s++;
	if (!*s)
		return (0);
	while (*s && *s != c)
		s++;
	return (1 + count_words(s, c));
}

static char	**split_recursive(const char *s, char c, char **arr, int i)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	if (!*s)
	{
		arr[i] = NULL;
		return (arr);
	}
	while (s[len] && s[len] != c)
		len++;
	arr[i] = ft_substr(s, 0, len);
	if (!arr[i])
	{
		while (--i >= 0)
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	return (split_recursive(s + len, c, arr, i + 1));
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split_recursive(s, c, arr, 0));
}
