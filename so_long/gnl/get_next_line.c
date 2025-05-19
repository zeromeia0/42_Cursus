/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:25:28 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/26 15:46:03 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*print;
	int			count;
	static char	file_str[BUFFER_SIZE + 1];

	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (file_str[0] == '\0')
		{
			count = read(fd, file_str, BUFFER_SIZE);
			if (count <= 0)
				break ;
			file_str[count] = '\0';
		}
		if (ft_strchr(file_str, '\n'))
			return (full_line(print, file_str));
		print = ft_strjoin(print, file_str);
		file_str[0] = '\0';
	}
	if (count < 0)
		return (free(print), NULL);
	return (print);
}
