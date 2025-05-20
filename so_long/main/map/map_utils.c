/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:44:00 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 19:58:22 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../z/so_long.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\n' && map[0][width])
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	create_walls(void)
{
	
}