/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_oreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:44 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 16:09:49 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void*))
{
	while (begin_list != 0)
	{
		if (begin_list->data != 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}