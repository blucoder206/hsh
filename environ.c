#include <stdio.h>
extern char **environ;
/**
* main - print the variables inside gobal variable environ
*
* Return: nothing
**/
int main(int argc, char **argv, char **env)
{
	printf("Address of environ:%p\n", environ);
	printf("Address of env:%p\n", env);
	return (0);
}
