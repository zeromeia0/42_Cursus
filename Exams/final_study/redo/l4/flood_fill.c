/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 08:18:04 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/05 08:24:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

void fill(char **map, t_point size, char target, int x, int y)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (map[y][x] == 'F' || map[y][x] != target)
		return ;
	map[y][x] = 'F';
	fill(map, size, target, x + 1, y);
	fill(map, size, target, x - 1, y);
	fill(map, size, target, x, y + 1);
	fill(map, size, target, x, y - 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.x, begin.y);
}