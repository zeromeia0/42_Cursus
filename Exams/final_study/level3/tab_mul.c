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

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int main(int argc, char **argv)
{
	int i = 1;
	while (i <= 9)
	{
		int nb = ft_atoi(argv[1]);
		ft_putnbr(i),
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(i * nb);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}