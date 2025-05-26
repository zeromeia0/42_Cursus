/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:07 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/26 17:32:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
char **realloc_map(char **old_map, int old_size, int new_size)
{
	char **new_map;
	int i;

	new_map = ft_calloc(sizeof(char *), (new_size + 1));
	if (!new_map)
		return (NULL);

	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = NULL;

	free(old_map);
	return (new_map);
}

int	get_map_height(char **map)
{
	t_CreateMap *mapData;

	mapData = ft_calloc(sizeof(t_CreateMap), 1);
	if (!mapData)
		return (0);	
	while (map[mapData->map_height])
		mapData->map_height++;
	return(mapData->map_height);
}
int	get_map_width(char **map)
{
	t_CreateMap *mapData;

	mapData = ft_calloc(sizeof(t_CreateMap), 1);
	if (!mapData)
		return (0);	
	while (map[0][mapData->map_width])
		mapData->map_width++;
	mapData->map_width--;	
	return(mapData->map_width);
}