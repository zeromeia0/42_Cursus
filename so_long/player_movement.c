/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:11:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/05 14:19:21 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gato	*so_long(void)
{
	static t_gato	gato_instance;

	return (&gato_instance);
}

int	handle_exit(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

bool	collision(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		exit(0);
	return (map[y][x] == '1');
}

int	keypress_to_walk(int keysym, void *param)
{
	t_mlx_data		*data = (t_mlx_data *)param;
	t_gato			*gato = so_long();
	t_create_map	map_info;
	static int		i;
	int				prev_x = gato->x;
	int				prev_y = gato->y;

	if ((keysym == 119 || keysym == 65362) && !collision(data->collision_activate, gato->x, gato->y - 1))
		gato->y -= 1;
	else if ((keysym == 97 || keysym == 65361) && !collision(data->collision_activate, gato->x - 1, gato->y))
		gato->x -= 1;
	else if ((keysym == 115 || keysym == 65364) && !collision(data->collision_activate, gato->x, gato->y + 1))
		gato->y += 1;
	else if ((keysym == 100 || keysym == 65363) && !collision(data->collision_activate, gato->x + 1, gato->y))
		gato->x += 1;
	map_info.map_width = prev_x;
	map_info.map_height = prev_y;
	draw_map(data, &map_info, "./textures/carpet.xpm");
	map_info.map_width = gato->x;
	map_info.map_height = gato->y;
	draw_map(data, &map_info, "./textures/gatinho.xpm");
	if (prev_x != gato->x || prev_y != gato->y)
		ft_printf("Steps: %d\n", i++);
	handle_exit(keysym, data);
	return (0);
}

int	loop(void *param)
{
	t_mlx_data		*data;
	t_sprite_data	*sprite;

	sprite = ft_calloc(sizeof(t_sprite_data), 1);
	data = param;
	sprite->sprite_address = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/gatinho.xpm", &sprite->width, &sprite->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite->sprite_address, so_long()->x * 80, so_long()->y * 80);
	mlx_destroy_image(data->mlx_ptr, sprite->sprite_address);
	free(sprite);
	return (1);
}


int game_exit(char **map, int x, int y)
{
	t_gato *cat_position;

	cat_position = malloc(sizeof(t_gato));
	if (!cat_position)
		return (0);
	x = cat_position->x;
	y = cat_position->y;
	if (map[y][x] == 'E')
		exit(0);
	return (1);
}