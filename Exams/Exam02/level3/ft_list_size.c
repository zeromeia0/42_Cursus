/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:02:59 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/19 19:06:28 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list *next;
	void	*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int i = 0;

	while (begin_list->next)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}