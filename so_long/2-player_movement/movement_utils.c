/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:34:36 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 18:58:25 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../z/so_long.h"

int keypress_to_walk(int keysym, void *param)
{
	t_mlx_basic_data *data = (t_mlx_basic_data *)param;
	t_gato *gato = so_long();

	handle_exit(keysym, data);

	if (keysym == 119 || keysym == 65362) // w
		gato->y -= 10;
	else if (keysym == 97 || keysym == 65361) // a
		gato->x -= 10;
	else if (keysym == 115 || keysym == 65364) // s
		gato->y += 10;
	else if (keysym == 100 || keysym == 65363) // d
		gato->x += 10;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, gato->path_to_gato, gato->x, gato->y);

	printf("Key pressed: %d | Position -> x: %d, y: %d\n", keysym, gato->x, gato->y);
	return (0);
}