/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/10 10:55:13 by vivaz-ca         ###   ########.fr       */
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

void super_duper_hiper_free(void (*f)(char **), t_general *general)
{
    if (!general)
        return;
    if (f && general->general_create_map && general->general_create_map->new_map)
        f(general->general_create_map->new_map);
    if (general->general_mlx_data)
    {
        if (general->general_mlx_data->win_ptr && general->general_mlx_data->mlx_ptr)
            mlx_destroy_window(general->general_mlx_data->mlx_ptr, general->general_mlx_data->win_ptr);
        if (general->general_mlx_data->mlx_ptr)
        {
            mlx_destroy_display(general->general_mlx_data->mlx_ptr);
            free(general->general_mlx_data->mlx_ptr);
        }
    }
    free(general->general_parse);
    free(general->general_create_map);
    free(general->general_mlx_data);
    free(general);
}
