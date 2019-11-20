#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *var = "PATH";
	printf("PATH: %s\n", getenv(var));
	return (0);
}
