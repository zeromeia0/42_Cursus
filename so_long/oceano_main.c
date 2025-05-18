/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oceano_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:11 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/18 21:25:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (1);
	mlx_window = mlx_new_window(mlx_connection, 800, 600, "oceano");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	mlx_loop(mlx_connection);
	
}