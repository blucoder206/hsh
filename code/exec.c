#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    if (execve(av[1], av, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
