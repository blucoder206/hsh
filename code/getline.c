#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	ssize_t readed_bytes;
	size_t numberbytes;
	char *string;

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
		printf("%s", string);
	}
	free(string);
	return (0);
}
