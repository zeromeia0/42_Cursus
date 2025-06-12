/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 18:00:32 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_general	*so_long_tudo(void)
{
	static t_general	general;

	return (&general);
}

static int	is_valid(int argc, t_general *gen)
{
	if (argc != 2)
		return (ft_printf(POR_MAPA), 0);
	gen->gen_create_map = ft_calloc(1, sizeof(t_create_map));
	if (!gen->gen_create_map)
		return (super_duper_hiper_free(), ft_printf("Deu BO 2\n"), 1);
	gen->gen_parse = ft_calloc(1, sizeof(t_parsing));
	if (!gen->gen_parse)
		return (super_duper_hiper_free(), ft_printf(MEM_ISSUE), 0);
	gen->gen_mlx_data = ft_calloc(1, sizeof(t_mlx_data));
	if (!gen->gen_mlx_data)
		return (super_duper_hiper_free(), 0);
	return (1);
}

static void	breaker(t_general *gen)
{
	make_map(gen->gen_create_map, gen->gen_mlx_data);
	gen->gen_mlx_data->collision = gen->gen_create_map->new_map;
	mlx_loop_hook(gen->gen_mlx_data->mlx_ptr, loop, gen->gen_mlx_data);
	mlx_key_hook(gen->gen_mlx_data->win_ptr, keypress_to_walk, gen);
	mlx_loop(gen->gen_mlx_data->mlx_ptr);
}

int	start_game(t_general *gen, char *map_path)
{
	int	len;

	gen->gen_mlx_data->mlx_ptr = mlx_init();
	if (!gen->gen_mlx_data->mlx_ptr)
		return (super_duper_hiper_free(), 0);
	gen->gen_create_map->new_map = ft_open_map(map_path);
	if (!gen->gen_create_map->new_map)
		return (ft_printf(ERROR_OPEN_MAP), super_duper_hiper_free(),
			0);
	gen->gen_parse->valid_map_file = map_path;
	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + (len - 4), ".ber", 4))
		return (ft_printf(BER),
			super_duper_hiper_free(), 0);
	if (!valid_params(gen->gen_create_map->new_map, gen->gen_parse)
		|| !valid_path(gen->gen_create_map->new_map))
		return (ft_printf("Mapa inválido\n"), super_duper_hiper_free(), 0);
	gen->gen_mlx_data->win_ptr = mlx_new_window(gen->gen_mlx_data->mlx_ptr,
			(get_map_width(gen->gen_create_map->new_map) * 80),
			(get_map_height(gen->gen_create_map->new_map) * 80), "So_Long");
	if (!gen->gen_mlx_data->win_ptr)
		return (ft_printf(WIN_ERROR), super_duper_hiper_free(),
			0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_general	*gen;

	gen = so_long_tudo();
	if (!is_valid(argc, gen))
		return (ft_printf(INUTIL), 1);
	if (!start_game(gen, argv[1]))
		return (1);
	breaker(gen);
	super_duper_hiper_free();
	return (0);
}
