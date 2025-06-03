/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:00:15 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 16:01:55 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list != 0)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}