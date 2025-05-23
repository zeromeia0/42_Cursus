// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/20 15:52:28 by vivaz-ca          #+#    #+#             */
// /*   Updated: 2025/05/23 18:57:56 by vivaz-ca         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../z/so_long.h"

// void	my_mlx_put_pixel(t_guide_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// unsigned int	my_mlx_get_pixel(t_guide_data *data, int x, int y)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	return (*(unsigned int*) dst);
// }

// void	render(t_guide_data *src, t_guide_data *dest, int x, int y)
// {
// 	int	x_pixel;
// 	int	y_pixel;
// 	unsigned int color;
	
// 	x_pixel = 0;
// 	while (x_pixel < 80)
// 	{
// 		y_pixel = 0;
// 		while (y_pixel < 80)
// 		{
// 			color = my_mlx_get_pixel(src, x_pixel, y_pixel);
// 			if (color != TRANSPARENT)
// 				my_mlx_put_pixel(dest, x_pixel, y_pixel, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_map(t_create_map *final_map, t_create_map *texture)
// {
// 	size_t	x;
// 	size_t	y;

// 	x = 0;
// 	while (x < texture->map_width)
// 	{
// 		y = 0;
// 		while (y < texture->map_heigh)
// 		{
// 			if (final_map->map[x][y] == '1')
// 				render(texture->acces_gato.cat_xpm, texture->mlx_b_data.game, x * 80, y * 80);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// int	get_map_line_count(const char *filepath)
// {
// 	int		fd;
// 	int		count;
// 	char	ch;
// 	int		read_bytes;

// 	count = 0;
// 	fd = open(filepath, O_RDONLY);
// 	if (fd < 0)
// 		return (-1);
// 	while ((read_bytes = read(fd, &ch, 1)) > 0)
// 	{
// 		if (ch == '\n')
// 			count++;
// 	}
// 	close(fd);
// 	return (count + 1); // lines = newlines + 1
// }