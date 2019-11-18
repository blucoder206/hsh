#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "separeme esta";
	char* t = strtok(string, " ");

	while (t != NULL)
	{
		printf("%s\n", t);
		t = strtok(NULL, " ");
	}
	return (0);
}
