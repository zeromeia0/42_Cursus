/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:38:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/22 17:04:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_open_map
{
	int		fd;
	char	*line;
	char	**map;
	int		lines;
}	t_open_map;

typedef struct	s_guide_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_guide_data;

typedef struct s_draw_map
{
	
}	t_draw_map;

char	**open_map(const char *filename);
#endif