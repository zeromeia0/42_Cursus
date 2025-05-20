/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:10:42 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/20 17:35:09 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

