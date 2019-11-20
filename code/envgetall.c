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
	i = 0;
    while (env[i] != NULL)
   {
		printf("%s\n", env[9]);
		i++;
	}
    return (0);
}

