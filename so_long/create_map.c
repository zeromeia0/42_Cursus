/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:36:08 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 15:02:38 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_create_map *newMap, t_mlx_data *data)
{
	while (newMap->new_map[newMap->map_height])
	{
		newMap->map_width = 0;
		while (newMap->new_map[newMap->map_height][newMap->map_width])
		{
			if (newMap->new_map[newMap->map_height][newMap->map_width] == '1')
				draw_map(data, newMap, "./textures/tijolinho.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == '0')
				draw_map(data, newMap, "./textures/carpet.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == 'E')
				draw_map(data, newMap, "./textures/house.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == 'P')
			{
				so_long()->x = newMap->map_width;
				so_long()->y = newMap->map_height;
			}
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == 'C')
				draw_map(data, newMap, "./textures/rato.xpm");
			newMap->map_width++;
		}
		newMap->map_height++;
	}
}
