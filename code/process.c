#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t father;
	pid_t child;

	father = getpid();
	child = fork();
	printf("parent process: %d\n", father);
	printf("child process: %d\n", child);
	return (0);
}
