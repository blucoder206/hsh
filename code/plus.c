#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;

	pid_t parent = getpid();

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
		printf("Child PID: %u\n", child_pid);
        char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

        printf("Before execve\n");
        if (execve(argv[0], argv, NULL) == -1)
        {
        perror("Error:");
        }
        printf("After execve\n");
        return (0);
        sleep(3);
    }
    else
    {
        wait(&status);
        printf("Oh, it's all better now\n");
    }
	printf("Parent PID: %u\n", parent);
    return (0);
}
