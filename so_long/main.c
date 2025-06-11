/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 08:48:55 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_general *general_tudo;
	int		len;

	general_tudo = ft_calloc(1, sizeof(t_general));
	if (!general_tudo)
 		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Deu BO\n"), 1);
 	if (argc != 2)
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Coloca o mapa animal\n"), 0);
	general_tudo->gen_create_map = ft_calloc(1, sizeof(t_create_map));
	if (!general_tudo->gen_create_map)
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Deu BO 2\n"), 1);
	general_tudo->gen_parse = ft_calloc(1, sizeof(t_parsing));
	if (!general_tudo->gen_parse)
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Falha de memória\n"), 0);
	general_tudo->gen_mlx_data = ft_calloc(1, sizeof(t_mlx_data));
	if (!general_tudo->gen_mlx_data )
		return (super_duper_hiper_free(free_map, general_tudo), 1);
		
	// TA DANDO B.O AQUI TBM
	general_tudo->gen_mlx_data->mlx_ptr = mlx_init();
	if (!general_tudo->gen_mlx_data->mlx_ptr)
		return (super_duper_hiper_free(free_map, general_tudo), 1);	
		
	general_tudo->gen_create_map->new_map = ft_open_map(argv[1]);
	general_tudo->gen_parse->valid_map_file = argv[1];
	len = ft_strlen(general_tudo->gen_parse->valid_map_file);
		if (len < 4 || ft_strncmp(general_tudo->gen_parse->valid_map_file + (len - 4), ".ber", 4))
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Mapa tem que ser um .ber\n"), 1);
	if (!valid_params(general_tudo->gen_create_map->new_map, general_tudo->gen_parse))
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Mapa inválido\n"), 1);

		
	// TA DANDO B.O AQUI TBM
	general_tudo->gen_mlx_data->win_ptr = mlx_new_window(general_tudo->gen_mlx_data->mlx_ptr, get_map_width(general_tudo->gen_create_map->new_map) * 80, get_map_height(general_tudo->gen_create_map->new_map) * 80, "So_Long");
	if (!general_tudo->gen_mlx_data->win_ptr)
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Erro ao criar a janela\n"), 1);
		
	make_map(general_tudo->gen_create_map, general_tudo->gen_mlx_data);
	general_tudo->gen_mlx_data->collision = general_tudo->gen_create_map->new_map;
	mlx_loop_hook(general_tudo->gen_mlx_data->mlx_ptr, loop, general_tudo->gen_mlx_data);
	mlx_key_hook(general_tudo->gen_mlx_data->win_ptr, keypress_to_walk, general_tudo);
	mlx_loop(general_tudo->gen_mlx_data->mlx_ptr);
	super_duper_hiper_free(free_map, general_tudo);
	return (0);
}



