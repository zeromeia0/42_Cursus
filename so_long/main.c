/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 16:21:35 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_mlx_data *data;
	t_CreateMap *newMap;
	t_spriteData *sprite;
	
	sprite = malloc(sizeof(t_spriteData));
	newMap = malloc(sizeof(t_CreateMap));
	if (!newMap || argc < 1)
		return (0);
	data = malloc(sizeof(t_mlx_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 800, "So_Long");
	newMap->new_map = ft_open_map(argv[1]);
	while (newMap->new_map[newMap->map_width++][newMap->map_height++] != '\0')
	{
		if (newMap->new_map[newMap->map_width][newMap->map_height] == '1')
			draw_map(newMap, "./textures/parede.xpm");
	}
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}