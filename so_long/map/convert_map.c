/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 19:17:03 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../z/so_long.h"

/* char	**open_map(const char *file)
{
	t_create_map	map_info;
	
	map_info.lines = 0;
	map_info.fd = open(file, O_RDONLY);
	if (map_info.fd < 0)
		return (NULL);
	while ((map_info.line = get_next_line(map_info.fd)) != NULL)
	{
		map_info.lines++;
		free(map_info.line);
	}
	close(map_info.fd);
	map_info.map = malloc(sizeof(char *) * (map_info.lines + 1));
	if (!map_info.map)
		return (NULL);
	map_info.fd = open(file, O_RDONLY);
	if (map_info.fd < 0)
		return (NULL);
	int i = 0;
	while ((map_info.line = get_next_line(map_info.fd)) != NULL)
		map_info.map[i++] = map_info.line;
	map_info.map[i] = NULL;
	close(map_info.fd);
	return map_info.map;
}


int	get_map_width(char **map)
{
	t_create_map *get_map_width;

	get_map_width->map_width = 0;
	while (map[0][get_map_width->map_width] != '\n' && map[0][get_map_width->map_width])
		get_map_width->map_width++;
	return (get_map_width->map_width);
}

int	get_map_height(char **map)
{
	t_create_map *get_map_height;

	get_map_height->map_heigh = 0;
	while (map[get_map_height->map_heigh])
		get_map_height->map_heigh++;
	return (get_map_height->map_heigh);
} */





























/* TESTANDO UMA CENA
int	output_map(char **argv)
{
	char	**map;
	map = open_map(argv[1]);
	if (!map)
	{
		printf("Failed to read map\n");
		return (1);
	}
		int		y = 0;
	while (map[y])
	{
		printf("%d: %s", y, map[y]);
		y++;
	}
	for (int j = 0; j < y; j++)
		free(map[j]);
	free(map);
	return (0);
}

 int main(int argc, char *argv[])
{
	if (argc > 1)
		output_map(argv);
	return (0);	typedef struct s_draw_map

	// compile convert_map.c ../../gnl/get_next_line.c ../../gnl/get_next_line_utils.c && ./a.out ../../maps/only_wall.ber

}  */