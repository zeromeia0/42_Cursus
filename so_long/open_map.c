/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:39 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 12:03:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_open_map(char *file)
{
	t_create_map *create_map;

	create_map->lines = 0;
	create_map = malloc(sizeof(t_create_map));
	if (!create_map)
		return (NULL);
	create_map->map_fd = open(file, O_RDONLY);
	if (create_map->map_fd < 3)
		return (write(1, "Map Invalid", 11));

	create_map->new_map = malloc(sizeof(char *));
	if (!create_map->new_map)
		return (NULL);
	while ((create_map->get_gnl_null = get_next_line(create_map->map_fd)))
	{
		create_map->new_map = realloc_map(create_map->new_map, create_map->lines, create_map->lines + 1);
		if (!create_map->new_map)
		{
			free(create_map->get_gnl_null);
			close(create_map->map_fd);
			return (write(1, "Deu BO no Malloc", 16));
		}
		create_map->new_map[create_map->lines++] = create_map->get_gnl_null;
		create_map->new_map[create_map->lines] = NULL;
	}
	close (create_map->map_fd);
	return (create_map->new_map);
}
