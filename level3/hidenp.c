#include <unistd.h>

char *ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i + 1);
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	char *chr_ret;
	int i;
	
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			chr_ret = ft_strchr(av[2], av[1][i]);
			if (chr_ret == NULL)
			{
				write(1, "0", 1);
				return (0);
			}
			av[2] = chr_ret;
			i++;
		}
		write(1, "1", 1);
	}
	write (1, "\n", 1);
}
