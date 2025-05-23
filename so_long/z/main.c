/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:09:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 21:43:13 by vivaz-ca         ###   ########.fr       */
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

int main(void)
{
	t_mlx_basic_data	basic_data;
	// t_mlx_xpm	xpm;
	t_create_map create_map;

	// create_map.map = open_map(argv[1]);

	
	basic_data.mlx_ptr = mlx_init();
	if (!basic_data.mlx_ptr)
		return (1);
	basic_data.win_ptr = mlx_new_window(basic_data.mlx_ptr, 800, 600, "So_Long");
	
	// mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, mlx_get_data_addr(), )
	if (!basic_data.win_ptr)
		return (1);
	mlx_key_hook(basic_data.win_ptr, keypress_to_walk, &basic_data);
	
	create_map.map = open_map("../0-textures/parede.xpm");
	int x = get_map_width(create_map.map);
	int y = get_map_height(create_map.map);
	void	*path_to_wall = mlx_xpm_file_to_image(basic_data.mlx_ptr, "../0-textures/parede.xpm", &x, &y);
	while(create_map.map[x][y])
	{
		if(create_map.map[x][y] == '1')
			mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, path_to_wall, x, y);
	}
			

	// GATO STUFF 
/* 	gato_init();
	if (!xpm.width)
		xpm.width = 5; 
	so_long()->path_to_gato = mlx_xpm_file_to_image(basic_data.mlx_ptr, "../0-textures/parede.xpm", &xpm.width, &xpm.heigh);
	if (!so_long()->path_to_gato)
		return (1);
	mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, so_long()->path_to_gato, so_long()->x, so_long()->y);
	 so_long()->path_to_gato = so_long()->path_to_gato; */
	
	// create_map();

	//CHAT GPR STUFF
	// create_map.map = open_map(argv[1]);
	// create_map.lines = get_map_line_count(argv[1]); // or store from open_map
	
	// int map_width = ft_strlen(create_map.map[0]);
	// int map_heigh = create_map.lines;
	// create_map.map_width = map_width;
	// create_map.map_heigh = map_heigh;
	
	// basic_data.mlx_ptr = mlx_init();
	// basic_data.win_ptr = mlx_new_window(basic_data.mlx_ptr,
	//                                     map_width * 80,
	//                                     map_heigh * 80,
	//                                     "So_Long");
	
	// create_map.mlx_b_data = basic_data;
	
	// int w = 80, h = 80;
	// create_map.acces_gato.cat_xpm = mlx_xpm_file_to_image(
	//     basic_data.mlx_ptr, "../textures/wall.xpm", &w, &h
	// );
	
	// // Create image buffer
	// create_map.mlx_b_data.game = mlx_new_image(basic_data.mlx_ptr,
	//                                            map_width * 80,
	//                                            map_heigh * 80);
	// create_map.texture.addr = mlx_get_data_addr(create_map.mlx_b_data.game,
	//                                             &create_map.texture.bits_per_pixel,
	//                                             &create_map.texture.line_length,
	//                                             &create_map.texture.endian);
	
	// // RENDER IT
	// draw_map(&create_map, &create_map);
	
	// // Put image to window
	// mlx_put_image_to_window(basic_data.mlx_ptr,
    //                     basic_data.win_ptr,
    //                     create_map.mlx_b_data.game,
    //                     0, 0);


	mlx_loop(basic_data.mlx_ptr);
	return (0);
}
