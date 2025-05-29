#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0, j;
	while (i < size)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			int temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i = 0;
		}
		else
			i++;
	}
}

  int main(void)
  {
	int tab[] = {999, 2, 143, 1, 1, 323};
	unsigned int size = 6;
	sort_int_tab(tab, size);
	for (unsigned int j = 0; j < size; j++)
		printf("%d ", tab[j]);
	return (0);
  }
