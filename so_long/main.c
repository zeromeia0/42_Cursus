/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 17:28:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_mlx_data *data;
	t_CreateMap *newMap;
	t_spriteData *sprite;
	
	sprite = ft_calloc(sizeof(t_spriteData), 1);
	newMap = ft_calloc(sizeof(t_CreateMap), 1);
	if (!newMap || argc < 1)
		return (0);
	data = ft_calloc(sizeof(t_mlx_data), 1);
	data->mlx_ptr = mlx_init();
	newMap->new_map = ft_open_map(argv[1]);
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_map_width(newMap->new_map) * 80, get_map_height(newMap->new_map) * 80, "So_Long");
	while (newMap->new_map[newMap->map_height])
	{
		newMap->map_width = 0;
		while (newMap->new_map[newMap->map_height][newMap->map_width])
		{
			if (newMap->new_map[newMap->map_height][newMap->map_width] == '1')
				draw_map(data, newMap, "./textures/tijolinho.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == '0')
				draw_map(data, newMap, "./textures/carpet.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == 'P')
				draw_map(data, newMap, "./textures/gato.xpm");
			else if (newMap->new_map[newMap->map_height][newMap->map_width] == 'C')
				draw_map(data, newMap, "./textures/rato.xpm");
			newMap->map_width++;
		}				
		newMap->map_height++;
	}
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}