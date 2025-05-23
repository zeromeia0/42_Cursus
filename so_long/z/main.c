/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:09:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 18:40:21 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gato *so_long(void)
{
	static t_gato gato_instance;
	return (&gato_instance);
}
void gato_init(void)
{
	so_long()->x = 0;
	so_long()->y = 0;
}

int main(int argc, char *argv[])
{
	t_mlx_basic_data	basic_data;
	// t_mlx_xpm	xpm;
	t_create_map create_map;


	create_map.map = open_map(argv[1]);

	
	basic_data.mlx_ptr = mlx_init();
	if (!basic_data.mlx_ptr)
		return (1);
	basic_data.win_ptr = mlx_new_window(basic_data.mlx_ptr, 800, 600, "So_Long");
	
	// mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, mlx_get_data_addr(), )
	if (!basic_data.win_ptr)
		return (1);
	mlx_key_hook(basic_data.win_ptr, keypress_to_walk, &basic_data);
	
	
	// GATO STUFF 
	/*gato_init();
	if (!xpm.width)
		xpm.width = 5; 
	so_long()->path_to_gato = mlx_xpm_file_to_image(basic_data.mlx_ptr, "../textures/gato.xpm", &xpm.width, &xpm.heigh);
	if (!so_long()->path_to_gato)
		return (1);
	mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, so_long()->path_to_gato, so_long()->x, so_long()->y);
	 so_long()->path_to_gato = so_long()->path_to_gato; */
	
	// create_map();
	mlx_loop(basic_data.mlx_ptr);
	return (0);
}
