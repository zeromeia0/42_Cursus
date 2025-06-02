/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 15:07:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_params(char **map)
{
	t_parsing *parse = calloc(sizeof(t_parsing), 1);
	if (!parse)
		return (ft_printf("Memory allocation failed\n"), 0);
	 parse->y = 0;
	while (map[parse->y])
	{
		parse->x = 0;
		while (map[parse->y][parse->x] && map[parse->y][parse->x] != '\n')
		{
			char c = map[parse->y][parse->x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (ft_printf("Invalid character: %c\n", c), 0);
			if (c == 'E')
				parse->exit += 1;
			if (c == 'P')
				parse->start += 1;
			if (c == 'C')
				parse->collect += 1;
			parse->x++;
		}
		parse->y++;
	}
	if (parse->exit != 1 || parse->start != 1 || parse->collect < 1)
		return (ft_printf("Esse mapa ta mal viado\n"), 0);
	free(parse);
	return (1);
}

static void fill(char **tab, t_parsing *size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size->fill_y || col >= size->fill_x)
        return;
    if (tab[row][col] == 'E' || tab[row][col] != target)
        return ;
    tab[row][col] = 'P';
    fill(tab, size, target, row -1, col); 
    fill(tab, size, target, row +1, col); 
    fill(tab, size, target, row, col - 1);
    fill(tab, size, target, row, col + 1);
}

int flood_fill(char **tab, t_parsing *size, t_parsing begin)
{
	int	x;
	int	y;

	y = 0;
    char target = tab[begin.fill_y][begin.fill_x];
    fill(tab, size, target, begin.fill_y, begin.fill_x);
	while (tab[y])
	{
		x = 0;
		while (tab[y][x] && tab[y][x] != '\n')
		{
			if (tab[y][x] == 'C' || tab[y][x] == 'E')
				return (ft_printf("Nao consegue pegar todos os coletaveis ou saida ta fechada"), 0);
			x++;
		}
		y++;
	}
	return (1);
}