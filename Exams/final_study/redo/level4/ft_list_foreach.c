/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:24:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/03 16:25:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != 0)
	{
		if (begin_list->data != 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}