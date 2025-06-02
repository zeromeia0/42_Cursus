/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:26:40 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 17:39:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void fill(char **tab, int width, int height, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= height || col >= width)
		return;
	if (tab[row][col] != '0' && tab[row][col] != 'C' && tab[row][col] != 'E')
		return;
	tab[row][col] = 'P';
	fill(tab, width, height, target, row - 1, col);
	fill(tab, width, height, target, row + 1, col);
	fill(tab, width, height, target, row, col - 1);
	fill(tab, width, height, target, row, col + 1);
}
int flood_fill(char **tab, int width, int height, int start_y, int start_x)
{
	int y = 0;
	int x;
	char target = tab[start_y][start_x];

	fill(tab, width, height, target, start_y, start_x);
	while (tab[y])
	{
		x = 0;
		while (tab[y][x] && tab[y][x] != '\n')
		{
			if (tab[y][x] == 'C' || tab[y][x] == 'E')
				return (ft_printf("Nao consegue pegar todos os coletaveis ou saida ta fechada\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
int valid_path(char **map)
{
	int width = get_map_width(map);
	int height = get_map_height(map);
	char **copy = copy_map(map);
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
