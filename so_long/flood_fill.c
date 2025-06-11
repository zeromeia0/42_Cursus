/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:26:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 17:35:32 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_flood_fill pos, int y, int x)
{
	if (y < 0 || x < 0 || y >= pos.height || x >= pos.width)
		return ;
	if (tab[y][x] != '0' && tab[y][x] != 'C'
		&& tab[y][x] != 'E' && tab[y][x] != 'P')
		return ;
	tab[y][x] = 'V';
	fill(tab, pos, y - 1, x);
	fill(tab, pos, y + 1, x);
	fill(tab, pos, y, x - 1);
	fill(tab, pos, y, x + 1);
}

int	flood_fill(char **tab, t_flood_fill pos, int y, int x)
{
	int	i;
	int	j;

	fill(tab, pos, y, x);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
				return (ft_printf("Can't pegar collect ou saida ta fechada\n"),
					0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(char **map)
{
	char			**copy;
	t_flood_fill	fill;

	fill.width = get_map_width(map);
	fill.height = get_map_height(map);
	copy = copy_map(map);
	if (!copy)
		return (ft_printf("Error: Falha ao copiar o mapa\n"), 0);
	if (!flood_fill(copy, fill, so_long()->y, so_long()->x))
	{
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}

char	**copy_map(char **map)
{
	int		i;
	int		width;
	char	**copy;

	i = -1;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		width = ft_strlen(map[i]);
		copy[i] = malloc(sizeof(char) * (width + 1));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			return (free(copy), NULL);
		}
		ft_strlcpy(copy[i], map[i], width + 1);
	}
	copy[i] = NULL;
	return (copy);
}
