#include <unistd.h>
#include <stdlib.h>
size_t	ft_atoi(char *s)
{
	int i;
	int sign;
	int num;
	size_t res;

	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (s[i] && s[i] >= 48 && s[i] <= 57)
	{
		num = s[i] - 48;
		res = res * 10 + num;
		i++;
	}
	return (res *sign);
}

void	ft_puthex(size_t num)
{
	char s[] = "0123456789abcdef";

	if (num > 16)
		ft_puthex(num / 16);
	write(1, &s[num % 16], 1);
}

int main(int ac, char **av)
{
	size_t num;

	char s[] = "0123456789abcdef";
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		if (num >= 0)
		{
			ft_puthex(num);
		}
	}
	write(1, "\n", 1);
}
