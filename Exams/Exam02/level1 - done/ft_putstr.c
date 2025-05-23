/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:52:04 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/08 14:59:31 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}

int main(void)
{
	ft_putstr("Salve rapazeada");
	return (0);
}
