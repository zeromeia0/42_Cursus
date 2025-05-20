/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 20:17:54 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../z/so_long.h"

char	**open_map(const char *filename)
{
	t_open_map	map_info;
	
	map_info.lines = 0;
	map_info.fd = open(filename, O_RDONLY);
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
	map_info.fd = open(filename, O_RDONLY);
	if (map_info.fd < 0)
		return (NULL);
	int i = 0;
	while ((map_info.line = get_next_line(map_info.fd)) != NULL)
		map_info.map[i++] = map_info.line;
	map_info.map[i] = NULL;
	close(map_info.fd);
	return map_info.map;
}


/* TESTANDO UMA CENA
int	output_map(char **argv)
{
	char	**map;
	int		y = 0;
	map = open_map(argv[1]);
	if (!map)
	{
		printf("Failed to read map\n");
		return (1);
	}
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
	return (0);	

	// compile convert_map.c ../../gnl/get_next_line.c ../../gnl/get_next_line_utils.c && ./a.out ../../maps/only_wall.ber

}  */
