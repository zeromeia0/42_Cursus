/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:35:47 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/31 20:37:39 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *create_new_node(void *data)
{
	t_list *new = malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = 0;
	}
	return (new);
}