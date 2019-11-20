#include "holberton.h"
extern char **environ;
char *_getenv(char *name)
{
	int i, len_value;
	char *copy_name, *value;

	copy_name = malloc(_strlen(name) + 2);
	_strcpy(copy_name,name);
	value = _strcat(copy_name, "=");
	len_value = _strlen(value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(value, environ[i], len_value) == 0)
		{
			free(copy_name);
			return(environ[i] + len_value);
		}
	}
}
int main (void) {
	char *str;
	const char s[2] = ":\n";
	char *token;
	str = _getenv("PATH");
	token = strtok(str, s);

	while( token != NULL )
	{
		printf( "%s\n", token );
		token = strtok(NULL, s);
   }
   return(0);
}
