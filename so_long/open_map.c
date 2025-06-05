/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/05 14:00:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_open_map(char *file)
{
	t_create_map	*create_map;

	create_map = ft_calloc(sizeof(t_create_map), 1);
	if (!create_map)
		return (NULL);
	create_map->lines = 0;
	create_map->map_fd = open(file, O_RDONLY);
	if (create_map->map_fd < 3)
		return (NULL);
	create_map->new_map = ft_calloc(sizeof(char *), 1);
	if (!create_map->new_map)
		return (NULL);
	while ((create_map->get_gnl_null = get_next_line(create_map->map_fd)))
	{
		create_map->new_map = realloc_map(create_map->new_map, create_map->lines, create_map->lines + 1);
		if (!create_map->new_map)
		{
			free(create_map->get_gnl_null);
			close(create_map->map_fd);
			return (NULL);
		}
		create_map->new_map[create_map->lines++] = create_map->get_gnl_null;
	}
	close (create_map->map_fd);
	char **result = create_map->new_map;
	free(create_map);
	return (result);
}

unsigned int	*get_sprite_pixel(t_sprite_data *data, int x, int y)
{
	return ((unsigned int *)(data->address + (y * data->line_len + x * (data->bpp / 8))));
}

void	draw_map(t_mlx_data *data, t_create_map *drawMap, char	*type)
{
	t_sprite_data	*texture;

	(void)drawMap;
	texture = ft_calloc(sizeof(t_sprite_data), 1);
	texture->address = mlx_xpm_file_to_image(data->mlx_ptr, type, &texture->width, &texture->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture->address, drawMap->map_width * 80, drawMap->map_height * 80);
	mlx_destroy_image(data->mlx_ptr, texture->address);
	free(texture);
}


