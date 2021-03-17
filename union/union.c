#include <stdio.h>
#include <unistd.h>

int if_doublon(char *str, int c)
{
	int i;

	i = 0;
	while(i < c)
	{
		if(str[i] == str[c])
			return 1;
		i++;
	}
	return(0);
}

int existing_char(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return(1);
		i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			if(if_doublon(argv[1], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while(argv[2][i] != '\0')
		{
			if(if_doublon(argv[2], i) == 0 && existing_char(argv[1], argv[2][i]) == 0)
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
