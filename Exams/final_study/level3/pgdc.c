#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0, a, b;
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		i += (a > b) ? b : a;
		while (i-- >= 1)
		{
			if (a % i == 0 && b % i == 0)
			{
				printf("%d", i);
				return (0);
			}
		}
	}
	printf("\n");
	return (0);
}