/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:03:36 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 16:18:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../0-minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../0-gnl/get_next_line.h"
# include "../2-gato/gato.h"

# define TRANSPARENT 0x00ff

typedef struct s_mlx__basic_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*game;
}	t_mlx_basic_data;

typedef struct	s_guide_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_guide_data;

typedef struct s_gato
{
	void	*path_to_gato;
	int	x;
	int	y;
	void	*cat_xpm;
}	t_gato;

typedef struct s_create_map
{
	t_mlx_basic_data	mlx_b_data;
	t_guide_data 		texture;
	t_gato				acces_gato;
	int					map_width;
	int					map_heigh;
	char				**map;
	char				*filename;
	int					line;
	int					lines;
	int					fd;
}	t_create_map;	


int handle_exit(int keysym, t_mlx_basic_data *data);
int keypress_to_walk(int keysym, void *param);
int keypress_to_walk(int keysym, void *param);
// t_gato	*so_long(void);
void	gato_init(void);
t_gato *so_long(void);
void	create_map(t_create_map *final_map, t_create_map *texture);
char	**open_map(const char *filename);

#endif
