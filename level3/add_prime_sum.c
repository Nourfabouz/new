#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char c;
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i;
	int res;
	int num;
	int sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while(str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = str[i] - 48;
		res = res * 10 + num;
		i++;
	}
	return (res *sign);
}

int is_prime(int n)
{
	int i;

	if (n == 2)
		return (0);
	i = 2;
	while (i <= n/2)
	{
		if (n % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	char *str;
	int num;
	int i;
	int sum;

	if (ac == 2)
	{
		str = av[1];
		num = ft_atoi(str);
		if (num == 1)
		{
			write(1, "1\n", 2);
			return (0);
		}
		if (num >= 0)
		{
			i = 2;
			sum = 0;
			while (i <= num)
			{
				if (!is_prime(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "0\n", 2);
	return (0);
}

