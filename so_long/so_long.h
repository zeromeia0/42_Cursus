/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/24 19:57:42 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "./gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**collision_activate;
}	t_mlx_data;

typedef struct s_create_map
{
	char	**new_map;
	int		map_fd;
	int		lines;
	char	*get_gnl_null;
	int	map_height;
	int	map_width;
}	t_CreateMap;

typedef struct s_sprite_data
{
	void	*address;
	int		width;
	int		height;
	int			bpp;
	int			line_len;
	void		*final_map;
	char		*sprite_address;
	void		*parede;
}	t_spriteData;

typedef struct s_gato
{
	int	x;
	int	y;
}	t_gato;



char 	**realloc_map(char **old_map, int old_size, int new_size);
char	**ft_open_map(char *file);
void	draw_map(t_mlx_data *data, t_CreateMap *drawMap, char	*type);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	get_map_height(char **map);
int	get_map_width(char **map);
int keypress_to_walk(int keysym, void *param);
int	loop(void *param);
t_gato *so_long(void);


#endif