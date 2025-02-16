#include <stdio.h>
int	check_num(char *str)
{
	int	i;
	int check;
	
	i = 0;
	check = 0;

	while (str[i])
	{
		if(str[i] == ' ')
			i++;
		else
		{
			check++;
			while (str[i] && str[i] != ' ')
				i++;
		}

	}
	if(check <= 0)
		return (0);
	return(1);
}
int main ()
{
	printf("%d\n", check_num("      "));
}