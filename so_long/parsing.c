/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/30 15:41:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_params(char **map)
{
	t_parsing *parse;
	
	parse->y = 0;
	while (map[parse->x][parse->y] && (map[parse->x][parse->y] == '0' || map[parse->x][parse->y] == '1'
			|| map[parse->x][parse->y] == 'C' || map[parse->x][parse->y] == 'E' || map[parse->x][parse->y] == 'P'))
	{
		while (parse->y < get_map_height(map))
		{
			parse->x = 0;
			while (parse->x < get_map_width(map))
			{
				if (map[parse->x][parse->y] == 'E')
					parse->exit += 1;
				if (map[parse->x][parse->y] == 'P')
					parse->start += 1;
				if (map[parse->x][parse->y] == 'C')
					parse->collect += 1;
				parse->x++;
			}
			parse->y++;
		}
	}
	if (parse->exit != 1 || parse->start != 1 || parse->collect < 1)
		return (ft_printf("Esse mapa ta mal viado"), 0);
	return (0);
}

void flood_fill(int x)
{
	
}