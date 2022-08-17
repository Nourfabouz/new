#include <stdio.h>

char	to_lower(char c)
{
	c = c + 32;
	return (c);
}

int	ft_atoi_base(const char	*str, int str_base)
{
	int i;
	int num;
	int sign;
	int res;
	char c;

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
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || \
			(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
	{
		c = str[i];
		if (c >= 'A' && c <= 'F')
			c = to_lower(c);
		if (c >= 'a' && c <= 'f')
			num = c - 87;
		if (str[i] >= '0' && str[i] <= '9')
			num = c - 48;
		if (num < str_base)
			res = res * str_base + num;
		i++;
	}
	return (res * sign);
}

int main()
{
	char s[] = "011i54789abdcgf";
	int num = ft_atoi_base(s, 2);
	printf("the num is %d", num);
}
