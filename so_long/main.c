/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:09:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 16:28:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_steps(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
	printf("You pressed the %d key\n", keysym);
	return (0);
}

int main(void)
{
	t_mlx_data data;
	t_mlx_xpm	xpm;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "So_Long");
	if (!data.win_ptr)
		return (1);

	// AQUI TA A IMAGEM DO TIJOLO
 	// xpm.path_to_tijolinho = mlx_xpm_file_to_image(data.mlx_ptr, "./tijolinho.xpm", &xpm.heigh, &xpm.width);
 	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, xpm.path_to_tijolinho, xpm.heigh, xpm.width);
	
	xpm.path_to_gatinho =   mlx_xpm_file_to_image(data.mlx_ptr, "./gato.xpm", &xpm.width, &xpm.heigh);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, xpm.path_to_gatinho, xpm.width, xpm.heigh);
	mlx_key_hook(data.win_ptr, count_steps, &data);
	mlx_loop(data.mlx_ptr);
}
