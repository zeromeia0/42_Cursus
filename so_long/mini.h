#ifndef MINI_H
#define MINI_H
# define MLX_ERROR -1
# define WIDTH 640
# define HEIGHT 480
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef	struct s_xpm
{
	void	*img;
	char	*path;
	int		orc_w;
	int		orc_h;
}	t_xpm;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_xpm	xmp;
}	t_data;

#endif