#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i;

	i = 2;
	while (i < n / 2)
	{
		if (n % i  == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int num;
	int i;

	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num >= 0)
		{
			i = 2;
			while (i < num / i)
			{
				if ((num % i) == 0 && is_prime(i))
				{
					num = num / i;
					printf("%d", i);
					printf("*");
				}
				else if (i == 2)
					i++;
				else
					i += 2;
			}
		
		printf("%d", num);
		}
	}
	printf("\n");
}
