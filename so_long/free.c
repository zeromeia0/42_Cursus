/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 09:01:02 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	super_duper_hiper_free(void (*f)(char **), t_general *gen)
{
	if (!gen)
		return ;
	if (f && gen->gen_create_map
		&& gen->gen_create_map->new_map)
		f(gen->gen_create_map->new_map);
	if (gen->gen_mlx_data)
	{
		if (gen->gen_mlx_data->win_ptr && gen->gen_mlx_data->mlx_ptr)
			mlx_destroy_window(gen->gen_mlx_data->mlx_ptr,
				gen->gen_mlx_data->win_ptr);
		if (gen->gen_mlx_data->mlx_ptr)
		{
			mlx_destroy_display(gen->gen_mlx_data->mlx_ptr);
			free(gen->gen_mlx_data->mlx_ptr);
		}
	}
	free(gen->gen_parse);
	free(gen->gen_create_map);
	free(gen->gen_mlx_data);
	free(gen);
}

int	handle_exit(int keysym, t_general *data)
{
	if (keysym == XK_Escape)
	{
		super_duper_hiper_free(free_map, data);
		exit(0);
	}
	return (0);
}
