#include <stdio.h>
#include <string.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;
	char *variable = "PATH";
	int res;
	i = 0;
    while (env[i] != NULL)
    {
		res = strncmp(variable, env[i], 4);
		if(res == 0)
		{
			printf("PATH:%s\n", env[i]);
			//printf("%s\n", env[i]);
		}
		i++;
    }
    return (0);
}
