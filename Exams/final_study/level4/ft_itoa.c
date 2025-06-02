#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

char *itoa(int nbr)
{
	int len = (nbr <= 0), n = nbr;
	while (n)
		n /= 10, len++;
	char *str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	unsigned int num = (nbr > 0) ? nbr : -nbr;
	while (len >= 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
		if (nbr < 0 || len == 0)
			str[0] = '-';
	}
	return (str);
}