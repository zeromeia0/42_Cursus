/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:15:11 by lshonta           #+#    #+#             */
/*   Updated: 2025/05/20 19:58:29 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../z/so_long.h"

// void	ft_read_map(t_init_map *data)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open(data->fn, O_RDONLY);
// 	line = get_next_line(fd);
// 	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
// 	i = 0;
// 	while (line)
// 	{
// 		data->map[i] = line;
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	data->map[i] = NULL;
// 	free(line);
// 	line = NULL;
// 	close(fd);
// }