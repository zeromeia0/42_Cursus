/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:23 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/16 14:45:38 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	 int i = 0, j, tab[256] = {0};
	 if (argc == 3)
	 {
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[2][j] == argv[1][i])
				{
					if (tab[(int)argv[1][i]] == 0)
					{
						tab[(int)argv[1][i]] = 1;
						write(1, &argv[1][i], 1);
					}
				}
				j++;
			}
			i++;
		}
	 }
	 write(1, "\n", 1);
	 return (0);
}