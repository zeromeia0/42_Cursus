/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:31:58 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/10 10:51:56 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_general *general_tudo;
	int		len;

	general_tudo = malloc(sizeof(t_general));
	if (!general_tudo)
 		return (ft_printf("Deu BO\n"), 1);
 	if (argc <= 1)
		return (ft_printf("Coloca o mapa animal\n"), 0);
	general_tudo->general_create_map = ft_calloc(1, sizeof(t_create_map));
	if (!general_tudo->general_create_map)
		return (ft_printf("Deu BO 2\n"), 1);
	general_tudo->general_parse = ft_calloc(1, sizeof(t_parsing));
	if (!general_tudo->general_parse)
		return (ft_printf("Falha de memória\n"), 0);
	general_tudo->general_mlx_data = ft_calloc(1, sizeof(t_mlx_data));
	if (!general_tudo->general_mlx_data )
		return (super_duper_hiper_free(free_map, general_tudo), 1);
	general_tudo->general_mlx_data->mlx_ptr = mlx_init();
	if (!general_tudo->general_mlx_data->mlx_ptr)
		return (super_duper_hiper_free(free_map, general_tudo), 1);	
		
		
	general_tudo->general_create_map->new_map = ft_open_map(argv[1]);
	general_tudo->general_parse->valid_map_file = argv[1];
	printf("teste1\n");

	
	len = ft_strlen(general_tudo->general_parse->valid_map_file);
	printf("teste2\n");
	if (len < 4 || ft_strncmp(general_tudo->general_parse->valid_map_file + (len - 4), ".ber", 4))
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Mapa tem que ser um .ber\n"), 1);
	printf("teste3\n");
	
	/* POPR QUE CARALHOS ISSO TA DANDO ERRADO */
	if (!valid_params(general_tudo->general_create_map->new_map, general_tudo->general_parse))
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Mapa inválido\n"), 1);
		
	printf("teste4\n");

	
	general_tudo->general_mlx_data->win_ptr = mlx_new_window(general_tudo->general_mlx_data->mlx_ptr, get_map_width(general_tudo->general_create_map->new_map) * 80, get_map_height(general_tudo->general_create_map->new_map) * 80, "So_Long");
	if (!general_tudo->general_mlx_data->win_ptr)
		return (super_duper_hiper_free(free_map, general_tudo), ft_printf("Erro ao criar a janela\n"), 1);
	make_map(general_tudo->general_create_map, general_tudo->general_mlx_data);
	general_tudo->general_mlx_data->collision_activate = general_tudo->general_create_map->new_map;
	mlx_loop_hook(general_tudo->general_mlx_data->mlx_ptr, loop, general_tudo->general_mlx_data);
	mlx_key_hook(general_tudo->general_mlx_data->win_ptr, keypress_to_walk, general_tudo);
	mlx_loop(general_tudo->general_mlx_data->mlx_ptr);
	mlx_destroy_window(general_tudo->general_mlx_data->mlx_ptr, general_tudo->general_mlx_data->win_ptr);
	mlx_destroy_display(general_tudo->general_mlx_data->mlx_ptr);
	return (0);
}



