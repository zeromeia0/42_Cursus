/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 21:45:16 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

unsigned int	*get_sprite_pixel(t_spriteData *data, int x, int y)
{
	return ((unsigned int *)(data->address + (y * data->line_len + x * (data->bpp / 8))));
}

void	draw_map(t_mlx_data *data, t_CreateMap *drawMap, char	*type)
{
	t_spriteData *texture;

	(void)drawMap;
	texture = ft_calloc(sizeof(t_spriteData),1 );
	texture->address = mlx_xpm_file_to_image(data->mlx_ptr, type, &texture->width, &texture->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture->address, drawMap->map_width * 80, drawMap->map_height * 80);
}
