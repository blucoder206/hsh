#include "holberton.h"
extern char **environ;
/**
* _getenv - get environ path data
* @pathaddress: variable to get
*
* Return: value of variable PATH
*/
char *_getenv(char *pathaddress)
{
	int i, len_value;
	char *cpy_nm;

	cpy_nm = malloc(_strlen(pathaddress) + 2);
	_strcpy(cpy_nm, pathaddress);
	_strcat(cpy_nm, "=");
	len_value = _strlen(cpy_nm);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(cpy_nm, environ[i], len_value) == 0)
		{
			free(cpy_nm);
			return (environ[i] + len_value);
		}
	}
}
/**
* input_split - split the string into an array
* @argv: user's input splitted
* @string: string without split
* @delimitator: character that will act as delimitator
*
* Return: argv
**/
char **input_split(char **argv, char *string, char *delimitator)
{
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
	char *paths[20];
	char *path;

	path = _getenv("PATH");
	input_split(paths, path, ":");
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

		printf("$ ");
		readed_bytes = getline(&string, &numberbytes, stdin);
		argv = malloc(readed_bytes * sizeof(*argv));
		if (readed_bytes == -1)
		{
			printf("Error\n");
		}
		else
		{
			input_split(argv, string, " \n");
			child_pid = fork();
			if (child_pid == 0)
			{
				for (path_i = 0; paths[path_i] != NULL; path_i++)
				{
					char *executable;
					executable = malloc(_strlen(paths[path_i]) + 5);
					 _strcpy(executable, paths[path_i]);
					_strcpy(executable, paths[path_i]);
					_strcat(executable, "/");
					_strcat(executable, argv[0]);
					if (stat(executable, &st) == 0)
					{
						if (execve(executable, argv, NULL) == -1)
						{
						//	printf("Error\n");
						}
					}

				}
				printf("Binary not found\n");
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
