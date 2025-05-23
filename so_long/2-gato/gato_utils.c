/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gato_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:10:42 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 16:00:49 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../z/so_long.h"


t_gato *so_long(void)
{
	static t_gato gato_instance;
	return (&gato_instance);
}
void gato_init(void)
{
	so_long()->x = 0;
	so_long()->y = 0;
}
