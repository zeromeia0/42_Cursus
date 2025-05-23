/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:19:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/23 09:24:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", atoi(argv[1]) + atoi(argv[3]));
		else if (argv[2][0] == '-')
			printf("%d", atoi(argv[1]) - atoi(argv[3]));
		else if (argv[2][0] == '*')
			printf("%d", atoi(argv[1]) * atoi(argv[3]));
		else if (argv[2][0] == '/')
			printf("%d", atoi(argv[1]) / atoi(argv[3]));
		else if (argv[2][0] == '%')
			printf("%d", atoi(argv[1]) + atoi(argv[3]));
	}
	printf("\n");
	return (0);
}