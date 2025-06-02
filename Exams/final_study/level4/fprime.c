#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv)
{
	int i = 2, num = 0;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
		{
			printf("1\n");
			return (0);
		}
		while (1 < num)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				num /= i;
				if (num > 1)
					printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}