/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 18:02:14 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../z/so_long.h"

void	init_map(char *argv[])
{
	char	*line;
	int fd;
	int	i;
	
	i = 0;
	line = get_next_line(fd);
	 while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
}

/* char	**ft_convert_map(char **map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (*map[y])
	{
		while (*map[x])
		{
			
		}
	}
} */
int main(void)
{
	
}