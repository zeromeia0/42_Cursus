/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/26 19:52:10 by vivaz-ca         ###   ########.fr       */
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
	if (!newMap)
		return (0);
	if (argc <= 1)
		return(ft_printf("Coloca o mapa animal"), 0);
	data = ft_calloc(sizeof(t_mlx_data), 1);
	data->mlx_ptr = mlx_init();
	newMap->new_map = ft_open_map(argv[1]);
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_map_width(newMap->new_map) * 80, get_map_height(newMap->new_map) * 80, "So_Long");
	make_map(newMap, data);
	data->collision_activate = newMap->new_map;
	mlx_loop_hook(data->mlx_ptr, loop, data);
	mlx_key_hook(data->win_ptr, keypress_to_walk, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}