#include <unistd.h>
#include <stdlib.h>
char **ft_split(char *s)
{
	int i;
	int j;
	int k;
	int flag;
	char **str;

	str = (char **)malloc(1000 * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] == ' ')
			i++;
		str[j] = malloc(1000);
		if (str[j] == NULL)
			return (NULL);
		k = 0;
		while (s[i] && s[i] != ' ')
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	char **s;
	int len;
	int i;

	if (ac == 2)
	{
		s = ft_split(av[1]);
		i = len;
		while (s[len])
		len++;
		i = len - 1;
		while (i >= 0)
		{
			ft_putstr(s[i]);
			if (i != 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
}
