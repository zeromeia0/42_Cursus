/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 16:56:37 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **realloc_map(char **old_map, int old_size, int new_size)
{
	char **new_map;
	int i;

	new_map = ft_calloc(sizeof(char *), (new_size + 1));
	if (!new_map)
		return (NULL);

	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = NULL;

	free(old_map);
	return (new_map);
}

char	**ft_open_map(char *file)
{
	t_CreateMap *CreateMap;
	
	CreateMap = ft_calloc(sizeof(t_CreateMap), 1);
	if (!CreateMap)
		return (NULL);
	CreateMap->lines = 0;
	CreateMap->map_fd = open(file, O_RDONLY);
	if (CreateMap->map_fd < 3)
		return (NULL);
	CreateMap->new_map = ft_calloc(sizeof(char *), 1);
	if (!CreateMap->new_map)
		return (NULL);
	while ((CreateMap->get_gnl_null = get_next_line(CreateMap->map_fd)))
	{
		CreateMap->new_map = realloc_map(CreateMap->new_map, CreateMap->lines, CreateMap->lines + 1);
		if (!CreateMap->new_map)
		{
			free(CreateMap->get_gnl_null);
			close(CreateMap->map_fd);
			return (NULL);
		}
		CreateMap->new_map[CreateMap->lines++] = CreateMap->get_gnl_null;
	}
	close (CreateMap->map_fd);
	return (CreateMap->new_map);
}
int	get_map_height(char **map)
{
	t_CreateMap *mapData;

	mapData = ft_calloc(sizeof(t_CreateMap), 1);
	if (!mapData)
		return (0);	
	while (map[mapData->map_height])
		mapData->map_height++;
	return(mapData->map_height);
}
int	get_map_width(char **map)
{
	t_CreateMap *mapData;

	mapData = ft_calloc(sizeof(t_CreateMap), 1);
	if (!mapData)
		return (0);	
	while (map[mapData->map_width])
		mapData->map_width++;
	return(mapData->map_width);
}
unsigned int	*get_sprite_pixel(t_spriteData *data, int x, int y)
{
	return ((unsigned int *)(data->address + (y * data->line_len + x * (data->bpp
				/ 8))));
}

void	draw_map(t_mlx_data *data, t_CreateMap *drawMap, char	*type)
{
	t_spriteData *texture;

	(void)drawMap;
	texture = ft_calloc(sizeof(t_spriteData),1 );
	texture->address = mlx_xpm_file_to_image(data->mlx_ptr, type, &texture->width, &texture->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture->address, drawMap->map_width * 80, drawMap->map_height * 80);
}
