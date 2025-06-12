/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/12 17:51:02 by vivaz-ca         ###   ########.fr       */
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

int	super_duper_hiper_free(void)
{
	t_general	*gen;

	gen = so_long_tudo();
	if (!gen)
		exit(EXIT_FAILURE);
	if (gen->gen_create_map->new_map)
		free_map(gen->gen_create_map->new_map);
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
	exit (EXIT_SUCCESS);
}

int	handle_exit(int keysym)
{
	if (keysym == XK_Escape)
		super_duper_hiper_free();
	return (0);
}
