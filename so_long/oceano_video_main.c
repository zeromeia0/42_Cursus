/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oceano_video_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:03:01 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 14:28:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/* 
OCEANO GITHUB CODE TO STEAL / STUDY LMAO GITHUB = 'https://github.com/suspectedoceano/mlx/tree/main/mlx_explained'
typedef struct s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}               t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}


int	main(void)
{
    t_mlx_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Oceano Tutorial");
    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }
    mlx_key_hook(data.win_ptr, handle_input, &data);
    mlx_loop(data.mlx_ptr);
}
/*
 /* 
 OCEANO WEIRD ASS NON FUNCTIONIN CLICKEABLE STUFF
 typedef struct s_mlx_data
 {
	 void	*mlx_ptr;
	 void	*win_ptr;
 }	t_mlx_data;
 
 int handle_input(int keysym, t_mlx_data *data)
 {
	 if (keysym == XK_Escape)
	 {
		 printf("The key %d has been pressed\n\n", keysym);
		 mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		 mlx_destroy_display(data->mlx_ptr);
		 free(data->mlx_ptr);
		 exit(1);
	 }
	 printf("The key %d had been pressed\n\n", keysym);
	 return (0);
 }
 
 int main(void)
 {
	 t_mlx_data data;
 
	 data.mlx_ptr = mlx_init();
	 if (!data.mlx_ptr)
		 return (1);
	 data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Oceano Tutorial");
	 if (!data.win_ptr)
		 return (1);
	 mlx_loop(data.mlx_ptr);
	 mlx_key_hook(data.win_ptr, handle_input, &data);
 }
  */
 