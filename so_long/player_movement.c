/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 18:17:04 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress_to_walk(int keysym, void *param)
{
	t_mlx_data *data = (t_mlx_data *)param;
	t_gato *gato = so_long();

	if (keysym == 119 || keysym == 65362) // w
		gato->y -= 10;
	else if (keysym == 97 || keysym == 65361) // a
		gato->x -= 10;
	else if (keysym == 115 || keysym == 65364) // s
		gato->y += 10;
	else if (keysym == 100 || keysym == 65363) // d
		gato->x += 10;

	printf("Key pressed: %d | Position -> x: %d, y: %d\n", keysym, gato->x, gato->y);
	return (0);
}