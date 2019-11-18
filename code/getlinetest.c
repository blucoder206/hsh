#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	ssize_t readed_bytes;
	size_t numberbytes;
	char *string;
    char *str2arr[80];
    int i, j;

    i = 0;

	numberbytes = 0;
	string = NULL;
	printf("$ ");
	readed_bytes = getline(&string, &numberbytes, stdin);
	if (readed_bytes == -1)
	{
		printf("Error");
	}
	else
	{
		printf("Full str: %s\n", string);
        str2arr[0] = strtok(string, " ");
        while (str2arr[i] != NULL)
        {
            i++;
            str2arr[i] = strtok(NULL, " ");
           
        }
        printf("i value is: %d\n", i);
        for (j = 0; j < i; j++)
        {
            printf("Element %d is %s\n", j, str2arr[j]);
        }
        str2arr[1] = "/usr/";
        if (execve(str2arr[0], str2arr, NULL) == -1)
        {
            perror("Error");
        }
        
    }
	free(string);
	return (0);
}
