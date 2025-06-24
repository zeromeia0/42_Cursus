/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:28:41 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/24 16:32:53 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	counter(char **separator)
{
	int	i = 0;
	while (separator && separator[i])
		i++;
	return (i);
}

static void	free_args(char **separator)
{
	int	i = 0;
	if (!separator)
		return;
	while (separator[i])
		free(separator[i++]);
	free(separator);
}

int	sentence(int argc, char **argv, int **stk_a, int **stk_b)
{
	char	**separator;
	int		count;
	int		i;

	separator = NULL;
	if (argc == 2 && strchr(argv[1], ' '))
	{
		separator = ft_split(argv[1], ' ');
		count = counter(separator);
	}
	else
	{
		separator = argv + 1;
		count = argc - 1;
	}
	*stk_a = malloc(sizeof(int) * count);
	*stk_b = malloc(sizeof(int) * count);
	if (!*stk_a || !*stk_b)
		return (write(2, "Error\n", 6), 1);
	i = 0;
	while (i < count)
	{
		(*stk_a)[i] = ft_atol(separator[i]);
		i++;
	}
	if (argc == 2 && strchr(argv[1], ' '))
		free_args(separator);
	return (count);
}
