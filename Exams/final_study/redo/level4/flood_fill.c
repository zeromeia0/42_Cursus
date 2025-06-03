/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:13:03 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 16:24:03 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	fiyl(map, size, target, x, y - 1);
}
void flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}
