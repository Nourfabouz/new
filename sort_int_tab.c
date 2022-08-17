
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

#include <stdio.h>

int main()
{
	int i;
	int tab[8] = {20, 10, 6, 200, 4, 205, 10, 115};
	sort_int_tab(tab, 8);
	i = 0;
	while (i < 8)
	{
		printf("%d ",tab[i]);
		i++;
	}
}
