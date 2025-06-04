/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:26:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 15:06:01 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, int width, int height, int row, int col)
{
	if (row < 0 || col < 0 || row >= height || col >= width)
		return ;
	if (tab[row][col] != '0' && tab[row][col] != 'C' && tab[row][col] != 'E' && tab[row][col] != 'P')
		return ;
	tab[row][col] = 'V';
	fill(tab, width, height, row - 1, col);
	fill(tab, width, height, row + 1, col);
	fill(tab, width, height, row, col - 1);
	fill(tab, width, height, row, col + 1);
}

int	flood_fill(char **tab, int width, int height, int start_y, int start_x)
{
	int	y;
	int	x;

	y = 0;
	fill(tab, width, height, start_y, start_x);
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'C' || tab[y][x] == 'E')
				return (ft_printf("Nao consegue pegar todos os coletaveis ou saida ta fechada\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_path(char **map)
{
	int		width;
	int		height;
	char	**copy;

	width = get_map_width(map);
	height = get_map_height(map);
	**copy = copy_map(map);
	if (!copy)
		return (ft_printf("Error: Falha ao copiar o mapa\n"), 0);
	if (!flood_fill(copy, width, height, so_long()->y, so_long()->x))
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

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		width = ft_strlen(map[i]);
		copy[i] = malloc(sizeof(char) * (width + 1));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], map[i], width + 1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
