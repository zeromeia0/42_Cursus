#include <stdlib.h>

int count_len(int nb)
{
	int i = 0;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb =/ 10;
		i++;
	}
	return (i);
}

char *itoa(int nbr)
{
	int len = count_len(nbr), i = 0;;
	char *str;
	unsigned int n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[i] = '-';
		n = -nbr;
	}
	else
		n = nbr;
	i = len - 1;
	while (n >= 10)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (str);

}

int count_len(int nbr)
{
	int i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nbr)
{
	int len = count_len(nbr);
	char *str;
	unsigned int n;
	int i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		n = -nbr;
	}
	else
		n = nbr;
	i = len - 1;
	while (n >= 10)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
