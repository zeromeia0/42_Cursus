/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:54 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/09 12:25:17 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_params(char **map, t_parsing *parse)
{
    int current_len;
    int i;

    parse->y = 0;
    parse->width = ft_strlen(map[0]);
	
    if (map[0][parse->width - 1] == '\n')
        parse->width--;
    while (map[parse->y])
    {
        parse->x = 0;
        current_len = ft_strlen(map[parse->y]);
        if (map[parse->y][current_len - 1] == '\n')
            current_len--;
        if (current_len != parse->width)
            return (ft_printf("Mapa não é retangular\n"), 0);

        if (map[parse->y][0] != '1' || map[parse->y][current_len - 1] != '1')
            return (ft_printf("Mapa não está cercado por '1'\n"), 0);
			
        while (parse->x < current_len)
        {
            char c = map[parse->y][parse->x];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
                return (ft_printf("Caractere inválido: %c\n", c), 0);
            if (c == 'E')
                parse->exit += 1;
            if (c == 'P')
                parse->start += 1;
            if (c == 'C')
                parse->collect += 1;
            parse->x++;
        }
        parse->y++;
    }
    i = 0;
    while (i < parse->width)
    {
        if (map[0][i] != '1')
            return (ft_printf("Parede de cima não está fechada com '1'\n"), 0);
        i++;
    }
    i = 0;
    while (i < parse->width)
    {
        if (map[parse->y - 1][i] != '1')
            return (ft_printf("Parede de baixo não está fechada com '1'\n"), 0);
        i++;
    }
    if (parse->exit != 1 || parse->start != 1 || parse->collect < 1)
        return (ft_printf("Esse mapa tá mal viado\n"), 0);
    return (1);
}


