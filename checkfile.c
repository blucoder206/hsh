#include "holberton.h"
/**
 * main - stat example
 * @ac: counter
 * @av: vector
 * Return: Always 0.
 */
int main(void)
{
//	unsigned int i;
	int i;
	struct stat st;
//	char cwd[PATH_MAX];
//	char slash[2] = "/";
//	char *router;
	char *av[8] =
		{
			"/usr/local/sbin/ls",
			"/usr/local/bin/ls",
			"/usr/sbin/ls",
			"/usr/bin/ls",
			"/sbin/ls",
			"/bin/ls",
			"/usr/games/ls",
			"/usr/local/games/ls"
		};

	
/**
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{}
	else
	{
		perror("getcwd() error");
		return (1);
	}
	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		router = _strcat(cwd, slash);
		printf("\nrouter is: %s\n", router);
		av[1] = _strcat(cwd, av[1]);
		printf("\nav[i] is: %s\n", av[i]);
		if (

*/
	for (i = 0; av[i] != NULL; i++)
	{
		if (stat(av[i], &st) == 0)
		{
			printf("%s found\n", av[i]);
		}
	//	i++;
	}
	return (0);
}
