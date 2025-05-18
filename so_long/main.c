/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:05:09 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/18 21:54:57 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "My first window!");
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





/* 
OCEANO BASIC MAIN FUNCTION WITH NO CLICKABLES
int main(void)
{
	void	*mlx_connection; // used to linx to init;
	void	*mlx_window;	//kinda obvious you dumbass 

	mlx_connection = mlx_init(); // initiate
	if (mlx_connection == NULL)
		return (1);
	mlx_window = mlx_new_window(mlx_connection, 800, 600, "oceano"); // create window 
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_connection);	//destroy display + free because malloc
		free(mlx_connection);
		return (1);
	}
	mlx_loop(mlx_connection); //event loop
	
	mlx_destroy_window(mlx_connection, mlx_window); // free everything at the end
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}
 */