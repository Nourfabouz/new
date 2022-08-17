#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str)
{
	char **s;
	int i;
	int j;
	int k;
	int flag;

	s = malloc(1000 * sizeof(char *));
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
		i++;
	j = 0;
	while (str[i])
	{
		flag = 0;
		while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
			i++;
		if (str[i])
		{
			s[j] = malloc(1000 * sizeof(char));
			flag = 2;
		}
		k = 0;
		while (str[i] && str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
		{
			s[j][k] = str[i];
			k++;
			i++;
		}
		if (flag == 2)
			s[j][k] = '\0';
		j++;
	}
	s[j] = NULL;
	return (s);
}

int main()
{
	char s[] = "      faiza hussein	mohamad                      abouzaher          ";
	char **str = ft_split(s);
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
}
