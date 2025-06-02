/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:07 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 21:46:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		bgn;
	int		end;
	char	*str;

	bgn = 0;
	end = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[bgn] && is_set(s1[bgn], set))
		bgn++;
	while (end > bgn && is_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(end - bgn + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + bgn, end - bgn);
	str[end - bgn] = 0;
	return (str);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dest;
	while (n--)
		*ptr++ = *((const unsigned char *)src++);
	return (dest);
}

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