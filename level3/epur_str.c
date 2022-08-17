#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char *str;

	if (ac == 2)
	{
		str = av[1];
		i = 0;
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		while (str[i])
		{
			if ((str[i] == ' ' || str[i] == '\t') && \
					(str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0'))
				write (1, " ", 1);
			else if ((str[i] != ' ' && str[i] != '\t'))
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
