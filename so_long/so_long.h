/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:24:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/11 09:00:09 by vivaz-ca         ###   ########.fr       */
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
# include ".minilibx-linux/mlx.h"
# include <stdbool.h>
# include "./my_printf/ft_printf.h"
#define CHECK_MAP_FILE ".ber"

typedef struct s_parsing
{
	int	exit;
	int	collect;
	int collected;
	int	start;
	int	x;
	int	y;
	int	fill_y;
	int	fill_x;
	char *valid_map_file;
	int width;
}	t_parsing;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**collision;
}	t_mlx_data;

typedef struct s_create_map
{
	char	**new_map;
	char	**result;
	int		map_fd;
	int		lines;
	char	*get_gnl_null;
	int		map_height;
	int		map_width;
}	t_create_map;

typedef struct s_sprite_data
{
	void	*address;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	void	*final_map;
	char	*sprite_address;
	void	*parede;
}	t_sprite_data;

typedef struct s_gato
{
	int	prev_x;
	int	prev_y;
	int	x;
	int	y;
	int gen_prev_x;
	int gen_prev_y;
}	t_gato;

typedef struct s_general{
	t_parsing 		*gen_parse;
	t_create_map	*gen_create_map;
	t_mlx_data 		*gen_mlx_data;
	t_gato			*gen_gato;
}	t_general;

typedef struct s_position {
	int x;
	int y;
} t_position;


void	draw_map(t_mlx_data *data, t_create_map *drawMap, char	*type);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	make_map(t_create_map *newMap, t_mlx_data *data);
void	free_map(char **map);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**realloc_map(char **old_map, int old_size, int new_size);
char	**ft_open_map(char *file);
char	**copy_map(char **map);
char	*ft_strtrim(char const *s1, char const *set);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		keypress_to_walk(int keysym, void *param);
int		loop(void *param);
int		ft_printf(const char *format, ...);
int valid_params(char **map, t_parsing *parse);
int		flood_fill(char **tab, int width, int height, int start_y, int start_x);	
t_gato	*so_long(void);
void	super_duper_hiper_free(void (*f)(char **), t_general *general);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	redraw_map_tiles(t_general *general, t_position prev, t_gato *gato);
bool	collision(char **map, int x, int y, t_general *general);
void	handle_move(int keysym, t_gato *gato,
t_general *general, t_position *prev);
int	handle_exit(int keysym, t_general *data);

#endif