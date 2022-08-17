#include <stdlib.h>
#include <unistd.h>

char **ft_split(char *s)
{
	int i;
	int j;
	int k;
	int flag;
	char **str;

	str = (char **)malloc(sizeof(char *) * 1000);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
		{
			str[j] = malloc(1000);
			flag = 1;
		}
		k = 0;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		if (flag == 1)
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
	int i;

	s = ft_split(av[1]);
	i = 1;
	if (s[1])
	{
		while (s[i])
		{
			ft_putstr(s[i]);
			write(1, " ", 1);
			i++;
		}
	}
	ft_putstr(s[0]);
	write(1, "\n", 1);
}
