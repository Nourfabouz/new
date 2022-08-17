#include <stdlib.h>
#include <stdio.h>

void	fill_chart(int n, char *str)
{
	int sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n > 9 || n < -9)
		fill_chart(n / 10, str - 1);
	(*str) = ((n % 10 * sign) + 48);
}

int count_chiffres(int n)
{
	int chiffres_number;

	chiffres_number = 0;
	while (n > 9 || n < -9)
	{
		chiffres_number++;
		n = n / 10;
	}
	if (n < 9 && n > -9 && n != 0)
		chiffres_number++;
	if (n < 0)
		chiffres_number++;
	return (chiffres_number);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int len;

	len = count_chiffres(nbr);
	printf("len is %d\n", len);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	  str[0] = '-';
	fill_chart(nbr, str + len - 1);
	str[len] = '\0';
	return (str);
}

#include <stdio.h>
int main(int ac, char **av)
{
	int num;
	char *s;

	num = atoi(av[1]);
	s = ft_itoa(num);
	printf("%s", s);
}
