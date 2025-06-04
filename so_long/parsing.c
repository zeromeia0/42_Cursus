/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/04 15:33:05 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_params(char **map)
{
	char		c;
	t_parsing	*parse;

	parse = calloc(sizeof(t_parsing), 1);
	if (!parse)
		return (ft_printf("Memory allocation failed\n"), 0);
	parse->y = 0;
	while (map[parse->y])
	{
		parse->x = 0;
		while (map[parse->y][parse->x] && map[parse->y][parse->x] != '\n')
		{
			c = map[parse->y][parse->x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (ft_printf("Invalid character: %c\n", c), 0);
			if (c == 'E')
				parse->exit += 1;
			if (c == 'P')
				parse->start += 1;
			if (c == 'C')
				parse->collect += 1;
			parse->x++;
		}
		parse->y++;
	}
	if (parse->exit != 1 || parse->start != 1 || parse->collect < 1)
		return (ft_printf("Esse mapa ta mal viado\n"), 0);
	free(parse);
	return (1);
}

