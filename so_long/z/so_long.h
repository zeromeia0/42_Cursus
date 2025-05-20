/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:03:36 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 19:58:11 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../main/map/map.h"
# include "../gnl/get_next_line.h"

typedef struct s_mlx__basic_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_basic_data;

typedef struct s_mlx_xpm
{
	void	*path_to_tijolinho;
	int		heigh;
	int		width;
}	t_mlx_xpm;

typedef struct s_new_sprite
{
	void	*img;
}	t_new_sprite;
//reference shit

// typedef struct s_graph
// {
// 	void	*wall;
// 	void	*empty;
// 	void	*collect;
// 	void	*exit;
// 	void	*player;
// 	void	*winner;
// }	t_graph;

// typedef struct s_init_map
// {
// 	int		hight;
// 	int		lenght;
// 	int		x;
// 	int		y;
// 	int		player;
// 	int		escape;
// 	int		count;
// 	int		step;
// 	char	**map;
// 	void	*wall;
// 	void	*mlx;
// 	void	*win;
// 	char	*fn;
// 	t_graph	*graph;

// }	t_init_map;

// void	ft_read_map(t_init_map *data);

int handle_exit(int keysym, t_mlx_basic_data *data);
int keypress_to_walk(int keysym, void *param);
int keypress_to_walk(int keysym, void *param);
// t_gato	*so_long(void);
void	gato_init(void);

#endif
