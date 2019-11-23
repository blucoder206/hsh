#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"

extern char **environ;
char *_getenv(char *pathaddress)
{
	int i, len_value;
	char *cpy_nm, *value;

	cpy_nm = malloc(_strlen(name) + 2)
	_strcpy(cpy_nm, pathaddress);
	len_value = _strlen(value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(value, environ[i], len_value) == 0)
		{
			free(cpy_nm);
			return(environ[i] + len_value);
		}
	}
}
/**
* input_split - split the string into an array
* @argv: user's input splitted
* @string: string without split
* Return: argv
**/
char **input_split(char **argv, char *string)
{
	const char delimitator[2] = " \n";
	char *token;
	int i = 0;

	token = strtok(string, delimitator);
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, delimitator);
	}
	argv[i] = 0;
	return (argv);
}
/**
* main - super simple shell
*
* Return: nothing
**/
int main(void)
{
	for (;;)
	{
		ssize_t readed_bytes;
		struct stat st;
		size_t numberbytes = 0;
		char *string = NULL;
		char **argv;
		char *token;
		pid_t child_pid;
		int status, path_i;
		char *paths[8] =
		{
			"/usr/local/sbin",
			"/usr/local/bin",
			"/usr/sbin",
			"/usr/bin",
			"/sbin",
			"/bin/ls",
			"/usr/games",
			"/usr/local/games"
		};
		printf("$ ");
		readed_bytes = getline(&string, &numberbytes, stdin);

		argv = malloc(readed_bytes * sizeof(*argv));

		if (readed_bytes == -1)
		{
			printf("Error\n");
		}
		else

		{
			input_split(argv, string);
			child_pid = fork();
			if (child_pid == 0)
			{
				for (path_i = 0; paths[path_i] != NULL; path_i++)
				{
					if (stat(paths[path_i], &st) == 0)
					{
						if (execve(paths[path_i], argv, NULL) == -1)
						{
//							printf("Error\n");
						}
					}
				}
			}
			else
			{
				wait(&status);
			}
		}
		free(string);
		free(argv);
	}
	return (0);
}
