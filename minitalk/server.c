/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:29:56 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/07/01 19:09:20 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid(void)
{
	pid_t process;
	process = getpid();
	printf("PID: %d\n", process);
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	print_pid();
	return (0);
}
