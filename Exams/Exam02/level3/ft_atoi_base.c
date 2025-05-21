/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:25:43 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/05/21 09:26:23 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int isvalid(int c, int base)
{
    if (c >= '0' && c <= '9')
        return (c - '0' < base);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10 < base);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10 < base);
    return (0);
}

int get_value(int c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int ft_atoi_base(const char *str, int base)
{
    int i = 0, res = 0, sign = 1;

    while (isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] && isvalid(str[i], base))
    {
        res = res * base + get_value(str[i]);
        i++;
    }
    return (res * sign);
}
