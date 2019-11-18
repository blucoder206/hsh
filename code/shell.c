#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
        int i;

        for (i = 0; av[i] != 00; i++)
        {
 
			printf("Before execve\n");
    		if (execve(av[0], av, NULL) == -1)
    		{
        		perror("Error:");
    		}
    		printf("After execve\n");
    		return (0);
        }
        return (0);
}

