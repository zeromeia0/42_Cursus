/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/06 11:21:57 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_mlx_data  *data;
    t_create_map *newMap;
    t_parsing   *parse;

    newMap = ft_calloc(1, sizeof(t_create_map));
    if (!newMap)
        return (0);
    if (argc <= 1)
        return (ft_printf("Coloca o mapa animal\n"), 0);
    parse = ft_calloc(1, sizeof(t_parsing));
    if (!parse)
        return (ft_printf("Falha de memória\n"), 1);
    data = ft_calloc(1, sizeof(t_mlx_data));
    data->mlx_ptr = mlx_init();
    data->parse = parse;
    newMap->new_map = ft_open_map(argv[1]);
    if (!valid_params(newMap->new_map, parse))
        return (ft_printf("Mapa inválido\n"), 1);
    data->win_ptr = mlx_new_window(data->mlx_ptr, get_map_width(newMap->new_map) * 80, get_map_height(newMap->new_map) * 80, "So_Long");
    make_map(newMap, data);
    data->collision_activate = newMap->new_map;
    mlx_loop_hook(data->mlx_ptr, loop, data);
    mlx_key_hook(data->win_ptr, keypress_to_walk, data);
    mlx_loop(data->mlx_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free_map(newMap->new_map);
    free(parse);
    free(newMap);
    free(data);
}


