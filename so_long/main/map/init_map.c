/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/22 17:14:39 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../z/so_long.h"

#define TRANSPARENT 0x00ff
void	my_mlx_put_pixel(t_guide_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_get_pixel(t_guide_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*) dst);
}

void	render(t_guide_data *src, t_guide_data *dest, int x, int y)
{
	int	x_pixel;
	int	y_pixel;
	unsigned int color;
	
	x_pixel = 0;
	while (x_pixel < 80)
	{
		y_pixel = 0;
		while (y_pixel < 80)
		{
			color = my_mlx_get_pixel(src, x_pixel, y_pixel);
			if (color != TRANSPARENT)
				my_mlx_put_pixel(dest, x_pixel, y_pixel, color);
			y++;
		}
		x++;
	}
}