#include <unistd.h>
#include <stdio.h>
#include <limits.h>
/**
* main - get the current working directory and store it in 'cwd'
*
* Return: pointer to a string containing the pathname of cwd.
**/
int main(void)
{
	char cwd[PATH_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd() error");
		return 1;
	}
	return 0;
}
