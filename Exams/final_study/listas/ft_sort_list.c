/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:10:46 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/02 16:15:32 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int temp;
	t_list *head;

	head = temp;
	if (!lst || !data)
		return (0);
	while ((*cmp)(lst->data, lst->next->data) != 0)
	{
		
	}
}