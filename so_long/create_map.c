/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:36:08 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 06:24:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_create_map *map, t_mlx_data *data)
{
	while (map->new_map[map->map_height])
	{
		map->map_width = 0;
		while (map->new_map[map->map_height][map->map_width])
		{
			if (map->new_map[map->map_height][map->map_width] == '1')
				draw_map(data, map, "./textures/tijolinho.xpm");
			else if (map->new_map[map->map_height][map->map_width] == '0')
				draw_map(data, map, "./textures/carpet.xpm");
			else if (map->new_map[map->map_height][map->map_width] == 'E')
				draw_map(data, map, "./textures/house.xpm");
			else if (map->new_map[map->map_height][map->map_width] == 'P')
			{
				so_long()->x = map->map_width;
				so_long()->y = map->map_height;
			}
			else if (map->new_map[map->map_height][map->map_width] == 'C')
				draw_map(data, map, "./textures/rato.xpm");
			map->map_width++;
		}
		map->map_height++;
	}
}
