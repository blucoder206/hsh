#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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
		size_t numberbytes = 0;
		char *string = NULL;
		const char s[2] = " \n";
		char **argv;
		char *token;
		int tahv = 0;
		pid_t child_pid;
		int status;

		printf("$ ");
		readed_bytes = getline(&string, &numberbytes, stdin);

		argv = malloc(readed_bytes * sizeof(*argv));

		if (readed_bytes == -1)
		{
			printf("Error\n");
		}
		else
		{
			token = strtok(string, s);
			while (token)
			{
				argv[tahv++] = token;
				token = strtok(NULL, s);
			}
			argv[tahv] = 0;
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					 printf("Error\n");
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
