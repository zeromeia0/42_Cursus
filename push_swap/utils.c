/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:06:05 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/06/26 12:31:08 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_base_value	*value(void)
{
	static t_base_value	value;

	return (&value);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long	count_digits_loser(long nb)
{
	long	count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
long	count_digits(long nb)
{
	long	count;

	count = 1;
	if (nb <= 9)
		return (count);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	get_most_digits(int argc, t_base_value *value, long *max_digits)
{
	int		i;
	long	digits;

	i = 0;
	*max_digits = count_digits(value->stack->stack_a[i]);
	while (++i < argc - 1)
	{
		digits = count_digits(value->stack->stack_a[i]);
		if (*max_digits < digits)
			*max_digits = digits;
	}
	return (int)(*max_digits);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	print_stuff(int argc, char *argv[], t_base_value *print)
{
	int	i;

	i = 1;
	(void)print;
	if (argc >= 2)
	{
		while (i < argc)
		{
			ft_printf("Digits: %ld\t| Argv[%d]: %ld\n",
				count_digits_loser(ft_atol(argv[i])), i, ft_atol(argv[i]));
			i++;
		}
	}
}

void	print_stack(const char *name, long *stack, int size)
{
	ft_printf("%s", name);
	for (int i = 0; i < size; i++)
		ft_printf("[%ld] ", stack[i]);
	ft_printf("\n");
}

int	minimum_len(long *stk)
{
	if (!stk)
		return (0);
	if (stk[0] && stk[1])
		return (2);
	if (stk[0])
		return (1);
	return (0);
}

char	*ft_substr(char const *value, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!value)
		return (NULL);
	if (start > ft_strlen(value))
		return (ft_strdup(""));
	if (ft_strlen(value + start) < len)
		len = ft_strlen(value + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (value[i] && j < len)
	{
		str[j] = value[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *value, int c)
{
	int i = 0;
	while (value[i])
	{
		if (value[i] == c)
			return ((char *)&value[i]);
		i++;
	}
	return (NULL);
}

int five_elements(int argc, char *argv[], t_base_value *value)
{
	(void)argc;
	(void)argv;
	value->stack->stack_a_length = 5;
	value->stack->stack_b_length = 0;
	value->stack->stack_a = malloc(sizeof(long) * 5);
	value->stack->stack_b = malloc(sizeof(long) * 5);
	if (!value->stack->stack_a || !value->stack->stack_b)
		return (free(value->stack->stack_a), free(value->stack->stack_b), free(value->stack), 0);
	for (int j = 0; j < 5; j++)
		value->stack->stack_a[j] = ft_atol(value->splited[j]);
	index_it(value);
	return (1);
}

int find_smallest_index(long *arr, int size)
{
	int i = 0;
	int min_i = 0;
	while (i < size)
	{
		if (arr[i] < arr[min_i])
			min_i = i;
		i++;
	}
	return min_i;
}

void sort_five(t_base_value *value)
{
    while (value->stack->stack_a_length > 3)
    {
        int min_index = find_smallest_index(value->stack->stack_a, value->stack->stack_a_length);
        int len = value->stack->stack_a_length;
        
        if (min_index <= len / 2)
        {
            while (min_index-- > 0)
                single_rotate(value->stack->stack_a, value->stack, 0);
        }
        else
        {
            while (min_index++ < len)
                reverse_rotate(value->stack->stack_a, value->stack, 0);
        }
        push_elements(value->stack->stack_a, value->stack->stack_b, value->stack, 1); // pb
    }
    sort_three(value);
    while (value->stack->stack_b_length > 0)
        push_elements(value->stack->stack_b, value->stack->stack_a, value->stack, 0); // pa
}

void sort_three(t_base_value *value)
{
    long *a = value->stack->stack_a;

    if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])  // Case: 2 1 3
        single_swap(a, 3, 0);
    else if (a[0] > a[1] && a[1] > a[2])  // Case: 3 2 1
    {
        single_swap(a, 3, 0);
        reverse_rotate(a, value->stack, 0);
    }
    else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])  // Case: 3 1 2
       single_rotate(a, value->stack, 1);
    else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])  // Case: 1 3 2
    {
		reverse_rotate(a, value->stack, 0);
		single_swap(a, 3, 0);
	}
    else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])  // Case: 2 3 1
    {
        single_rotate(a, value->stack, 1);
        single_rotate(a, value->stack, 1);
    }
}
