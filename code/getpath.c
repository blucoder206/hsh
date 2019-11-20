#include <stdio.h>
#include <string.h>

int main(int ac, char **av, char **environ)
{
	if (ac == 2)
	{
		char *userinput = av[1];
		int inputlen, i;
		char *value;
		value = strcat(userinput, "=");
		inputlen = strlen(value);
		for (i = 0; environ[i] != NULL; i++)
		{
			if (strncmp(value, environ[i], inputlen) == 0)
			{
				printf("%s\n", environ[i]+inputlen);
				break;
			}
		}
	}
	else
	{
		printf("Usage: %s PATH\n", av[0]);
	}
	return (0);
}
