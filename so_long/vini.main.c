#include "mini.h"

void	img_pixel_put(t_img *img, int x, int y, int color)

{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;

}

int	render_rect(t_img *img, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y < rect.y + rect.height)
	{
		x = rect.x;

		while (x < rect.x + rect.width)
			img_pixel_put(img, x++, y, rect.color);
		y++;
	}
	return (0);
}

int	render(t_data *var)
{
	if (var->win == NULL)
		return (MLX_ERROR);
//	render_rect(&var->img, green);
//	render_rect(var->xmp.img, orc);
	mlx_put_image_to_window(var->mlx, var->win, var->img.mlx_img, 0, 0);
	mlx_put_image_to_window(var->mlx, var->win, var->xmp.img, WIDTH / 2, HEIGHT / 2);
	return (0);
}



int	main(void)

{
	t_data	var;
	var.mlx = mlx_init();
	if (!var.mlx)
	// TODO: HANDLE ERROR
		return (MLX_ERROR); 
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Title");
	if (!var.win)
	// TODO: HANDLE ERROR
		return (MLX_ERROR);
	var.img.mlx_img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	if (!var.img.mlx_img)
	//	TODO: HANDLE ERROR
		return (MLX_ERROR);
	var.img.addr = mlx_get_data_addr(var.img.mlx_img, &var.img.bpp, &var.img.line_len, &var.img.endian);
	if (!var.img.addr)
	//	TODO: HANDLE ERROR
		return (MLX_ERROR);
	var.xmp.path = "./assets/orc.xpm";
	var.xmp.orc_w = WIDTH / 2;
	var.xmp.orc_h = HEIGHT / 2;
	var.xmp.img = mlx_xpm_file_to_image(var.mlx, var.xmp.path, &var.xmp.orc_w, &var.xmp.orc_h);
//	if (!var.xmp.img)
	//	TODO: HANDLE ERROR
//		return (MLX_ERROR);
	mlx_loop_hook(var.mlx, &render, &var);
	mlx_loop(var.mlx);

}