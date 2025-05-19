/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:03:36 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 18:50:55 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

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

typedef struct s_gato
{
	void	*path_to_gato;
	int	x;
	int	y;
}	t_gato;

int handle_exit(int keysym, t_mlx_basic_data *data);
int handle_keypress(int keysym, void *param);

#endif
