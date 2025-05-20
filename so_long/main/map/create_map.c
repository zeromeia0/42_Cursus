/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 17:40:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_image
{
	void	*image;
	int		height;
	int		width;
}	t_image;

/* t_image	*new_image_from_file(char	*path)
{
	t_image	*image;

	if (!path)
		return (NULL);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_xpm_file_to_image(global_mlx()->mlx, path,
			&image->width, &image->height);
	if (!image->image)
		return (free(image), NULL);
	return (image);
} */

void	render_map(char *path)
{
	t_new_sprite *render;

	if (!path)
		return (NULL);
	render = malloc(sizeof(t_new_sprite));
	if (!render)
		return (NULL);
	render->img = new_image_from_file("./textures/parede.xpm");
	if (!render->img)
		return (NULL);
}

void	generate_map(char c)
{
	if (c == '1') // EMPTY SPACE
		c = '0';
	return ;	
}