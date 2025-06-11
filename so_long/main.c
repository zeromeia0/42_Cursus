/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 18:30:22 by vivaz-ca         ###   ########.fr       */
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
		return (ft_printf("Coloca o mapa animal\n"), 0);
	gen->gen_create_map = ft_calloc(1, sizeof(t_create_map));
	if (!gen->gen_create_map)
		return (super_duper_hiper_free(), ft_printf("Deu BO 2\n"), 1);
	gen->gen_parse = ft_calloc(1, sizeof(t_parsing));
	if (!gen->gen_parse)
		return (super_duper_hiper_free(), ft_printf("Falha de memória\n"), 0);
	gen->gen_mlx_data = ft_calloc(1, sizeof(t_mlx_data));
	if (!gen->gen_mlx_data)
		return (super_duper_hiper_free(), 0);
	return (1);
}
static void	breaker_1(t_general *gen)
{
	make_map(gen->gen_create_map, gen->gen_mlx_data);
	gen->gen_mlx_data->collision = gen->gen_create_map->new_map;
	mlx_loop_hook(gen->gen_mlx_data->mlx_ptr, loop, gen->gen_mlx_data);
	mlx_key_hook(gen->gen_mlx_data->win_ptr, keypress_to_walk, gen);
	mlx_loop(gen->gen_mlx_data->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int			len;

	if (!is_valid(argc, so_long_tudo()))
		return (ft_printf("ta tudo mal essa merda"), 1);
	so_long_tudo()->gen_mlx_data->mlx_ptr = mlx_init();
	if (!so_long_tudo()->gen_mlx_data->mlx_ptr)
		return (super_duper_hiper_free(), 1);
	so_long_tudo()->gen_create_map->new_map = ft_open_map(argv[1]);
	so_long_tudo()->gen_parse->valid_map_file = argv[1];
	len = ft_strlen(so_long_tudo()->gen_parse->valid_map_file);
	if (len < 4 || ft_strncmp(so_long_tudo()->gen_parse->valid_map_file + (len - 4),
			".ber", 4))
		return (ft_printf("Mapa tem que ser um .ber\n"),
			super_duper_hiper_free(), 1);
	if (!valid_params(so_long_tudo()->gen_create_map->new_map, so_long_tudo()->gen_parse))
		return (ft_printf("Mapa inválido\n"), super_duper_hiper_free(), 1);
	so_long_tudo()->gen_mlx_data->win_ptr = mlx_new_window(so_long_tudo()->gen_mlx_data->mlx_ptr,
			(get_map_width(so_long_tudo()->gen_create_map->new_map) * 80),
			(get_map_height(so_long_tudo()->gen_create_map->new_map) * 80), "So_Long");
	if (!so_long_tudo()->gen_mlx_data->win_ptr)
		return (ft_printf("Erro ao criar a janela\n"), super_duper_hiper_free(),
			1);
	breaker_1(so_long_tudo());
	super_duper_hiper_free();
	return (0);
}
