/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:10:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/10 21:33:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_short
{
	char	**strs;
	int		i;
	int		k;
}	t_short;

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

int	make_short(char const *s, char c, t_short *var)
{
	int		start;

	while (s[var->k] == c && s[var->k])
		var->k++;
	start = var->k;
	while (s[var->k] != c && s[var->k])
		var->k++;
	var->strs[var->i] = ft_substr(s, start, var->k - start);
	if (!var->strs[var->i])
	{
		var->strs[var->i] = NULL;
		return (0);
	}
	var->i++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	t_short	var;

	var.i = 0;
	var.k = 0;
	if (!s)
		return (NULL);
	var.strs = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (var.strs)
		return (NULL);
	while (s[var.k])
	{
		if (s[var.k] != c)
			make_short(s, c, &var);
		else
			var.k++;
	}
	var.strs[var.i] = NULL;
	return (var.strs);
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
