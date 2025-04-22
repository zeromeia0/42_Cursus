#include "ft_printf.h"
#include "stdio.h"

int main()
{
	fclose(stdout);
	fprintf(stderr, "PRINTF: %d\n", printf("teste123\n"));
	fprintf(stderr, "FT_PRINTF: %d\n", ft_printf("teste123\n"));
}
