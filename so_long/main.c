/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/09 13:27:59 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_mlx_data	*data;
	t_create_map	*newMap;
	t_parsing	*parse;
	int		len;

	if (argc <= 1)
		return (ft_printf("Coloca o mapa animal\n"), 0);
	newMap = ft_calloc(1, sizeof(t_create_map));
	if (!newMap)
		return (0);
	parse = ft_calloc(1, sizeof(t_parsing));
	if (!parse)
		return (ft_printf("Falha de memória\n"), 0);
	data = ft_calloc(1, sizeof(t_mlx_data));
	if (!data)
		return (super_duper_hiper_free(free_map, parse, NULL, newMap), 0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (super_duper_hiper_free(free_map, parse, data, newMap), 0);
	data->parse = parse;
	newMap->new_map = ft_open_map(argv[1]);
	parse->valid_map_file = argv[1];
	len = ft_strlen(parse->valid_map_file);
	if (len < 4 || ft_strncmp(parse->valid_map_file + (len - 4), ".ber", 4))
		return (super_duper_hiper_free(free_map, parse, data, newMap),
				ft_printf("Mapa tem que ser um .ber\n"), 0);
	if (!valid_params(newMap->new_map, parse))
		return (super_duper_hiper_free(free_map, parse, data, newMap),
				ft_printf("Mapa inválido\n"), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_map_width(newMap->new_map) * 80, get_map_height(newMap->new_map) * 80, "So_Long");
	if (!data->win_ptr)
		return (super_duper_hiper_free(free_map, parse, data, newMap),
				ft_printf("Erro ao criar a janela\n"), 1);
	make_map(newMap, data);
	data->collision_activate = newMap->new_map;
	mlx_loop_hook(data->mlx_ptr, loop, data);
	mlx_key_hook(data->win_ptr, keypress_to_walk, data);
	mlx_loop(data->mlx_ptr);
	super_duper_hiper_free(free_map, parse, data, newMap);
	free(data->mlx_ptr);
	free(newMap->new_map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	return (0);
}



