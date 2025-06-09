/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/09 13:11:47 by vivaz-ca         ###   ########.fr       */
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

void	super_duper_hiper_free(void (*f)(char **), t_parsing *parse, t_mlx_data *data, t_create_map *new_map)
{
	if (new_map && f && new_map->new_map)
		f(new_map->new_map);
	if (data && data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free (parse);
	free(new_map);
	free(data);
}
