#include <stdio.h>


int main(int ac, char **av, char **env)
{
	int i=0;
	char *userinput = "PATH";

	while(env[i] != NULL)Y
	{
		printf("%s\n",env[i]);
		i++;
	}
	return 0;
}
