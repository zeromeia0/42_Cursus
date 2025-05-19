/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:09:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 18:50:10 by vivaz-ca         ###   ########.fr       */
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

int handle_keypress(int keysym, void *param)
{
	t_mlx_basic_data *data = (t_mlx_basic_data *)param;
	t_gato *gato = so_long();

	handle_exit(keysym, data);

	if (keysym == 119) // w
		gato->y -= 10;
	else if (keysym == 97) // a
		gato->x -= 10;
	else if (keysym == 115) // s
		gato->y += 10;
	else if (keysym == 100) // d
		gato->x += 10;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, gato->path_to_gato, gato->x, gato->y);

	printf("Key pressed: %d | Position -> x: %d, y: %d\n", keysym, gato->x, gato->y);
	return (0);
}

int main(void)
{
	t_mlx_basic_data	data;
	t_mlx_xpm	xpm;

	gato_init();

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);

	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "So_Long");
	if (!data.win_ptr)
		return (1);
	so_long()->path_to_gato = mlx_xpm_file_to_image(data.mlx_ptr, "./gato.xpm", &xpm.width, &xpm.heigh);
	if (!so_long()->path_to_gato)
		return (1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, so_long()->path_to_gato, so_long()->x, so_long()->y);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	so_long()->path_to_gato = so_long()->path_to_gato;
	mlx_loop(data.mlx_ptr);
	return (0);
}
