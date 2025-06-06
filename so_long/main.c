/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/06 11:11:30 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_mlx_data *data;
	t_create_map *newMap;

	newMap = ft_calloc(sizeof(t_create_map), 1);
	if (!newMap)
		return (0);
	if (argc <= 1)
		return(ft_printf("Coloca o mapa animal\n"), 0);
	data = ft_calloc(sizeof(t_mlx_data), 1);
	data->mlx_ptr = mlx_init();
	newMap->new_map = ft_open_map(argv[1]);
	if (!valid_params(newMap->new_map))
		return (ft_printf("Mapa inválido\n"), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_map_width(newMap->new_map) * 80, get_map_height(newMap->new_map) * 80, "So_Long");
	make_map(newMap, data);
	data->collision_activate = newMap->new_map;
	mlx_loop_hook(data->mlx_ptr, loop, data);
	mlx_key_hook(data->win_ptr, keypress_to_walk, data);

	char **copy = copy_map(newMap->new_map);
	if (!copy)
		return (ft_printf("Erro ao copiar mapa\n"), 1);
	if (!flood_fill(copy, get_map_width(copy), get_map_height(copy), so_long()->y, so_long()->x))
	{
		free_map(copy);
		return (ft_printf("Mapa inválido\n"), 1);
	}	
	free_map(copy);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(newMap->new_map);
	free(newMap);
	free(data);
}

