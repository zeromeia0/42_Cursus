#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0, result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void ft_putnbr(int nb)
{
	if (nb >= 16)
		ft_putnbr(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int nbr = ft_atoi(argv[1]);
		ft_putnbr(nbr);
	}
	write(1, "\n", 1);
	return (0);
}