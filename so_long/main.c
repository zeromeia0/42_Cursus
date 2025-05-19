/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:09:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 20:50:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(void)
{
	t_mlx_basic_data	basic_data;
	t_mlx_xpm	xpm;

	gato_init();

	basic_data.mlx_ptr = mlx_init();
	if (!basic_data.mlx_ptr)
		return (1);
	basic_data.win_ptr = mlx_new_window(basic_data.mlx_ptr, 800, 600, "So_Long");
	if (!basic_data.win_ptr)
		return (1);
	so_long()->path_to_gato = mlx_xpm_file_to_image(basic_data.mlx_ptr, "./textures/gato.xpm", &xpm.width, &xpm.heigh);
	if (!so_long()->path_to_gato)
		return (1);
	mlx_put_image_to_window(basic_data.mlx_ptr, basic_data.win_ptr, so_long()->path_to_gato, so_long()->x, so_long()->y);
	mlx_key_hook(basic_data.win_ptr, keypress_to_walk, &basic_data);
	so_long()->path_to_gato = so_long()->path_to_gato;
	mlx_loop(basic_data.mlx_ptr);
	return (0);
}
