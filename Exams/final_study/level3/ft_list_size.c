/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:53:51 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/29 08:55:06 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
} 	t_list;

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}