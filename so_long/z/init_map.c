/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/22 16:57:13 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
/* 
void	my_mlx_put_pixel(t_canva_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	my_mlx_get_pixel(t_canva_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
	return (*(unsigned int*) dest);
}

void	draw(t_canva_data src, t_canva_data dest, int x, int y)
{
	int				x_pixel;
	int				y_pixel;
	unsigned int	color;

	y_pixel = 0;
	while (y_pixel < 80)
	{
		x_pixel = 0;
		while (x_pixel < 80)
		{
			color = my_mlx_pixel_get(&src, x_pixel, y_pixel);
			if (color != TRANSPARENT)
				my_mlx_pixel_put(&dest, x_pixel + x, y_pixel + y, color);
			x_pixel++;
		}
		y_pixel++;
	}
}

void	map_drawer(t_map *map, t_texture *img)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				draw(img->wall, img->canva, x * 80, y * 80);
			else if (map->map[y][x] == '0' || map->map[y][x] == 'P'
				|| map->map[y][x] == 'C')
				draw(img->floor, img->canva, x * 80, y * 80);
			else if (map->map[y][x] == 'E')
				draw(img->canva, img->canva, x * 80, y * 80);
			x++;
		}
		y++;
	}
}
 */