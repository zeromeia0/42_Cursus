/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:29:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/07/10 06:06:12 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_it(int signal_received)
{
	static unsigned char	buff;
	static int				i;

	buff = buff | (signal_received == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &buff, 1);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, print_it);
	signal(SIGUSR2, print_it);
	while (1)
		pause();
	return (0);
}
