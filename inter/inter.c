#include <unistd.h>
#include <stdio.h>

int	ifdoublon(char *str, int c)
{
	int i;

	i = 0;
	while(i < c)
	{
		if (str[i] == str[c])
			return(1);
		i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			j = 0;
			while(argv[2][j] != '\0')
			{
				if(argv[1][i] == argv[2][j] && ifdoublon(argv[1], i) == 0)
				{
					write(1, &argv[1][i], 1);
					break;
				}
				j++;

			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
