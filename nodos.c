#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
char *_getenv(char *name)
{
    int i, len_value;
    char *copy_name, *value;

    copy_name = malloc(strlen(name) + 2);
    strcpy(copy_name,name);
    value = strcat(copy_name, "=");
    len_value = strlen(value);

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
    size_t readed_bytes;
    const char s[2] = ":\n";
    char *token;
    char **argv;
    int tahv = 0, n;

    str = _getenv("PATH");
    readed_bytes = (strlen(str));
    argv = malloc(readed_bytes * sizeof(*argv));

    token = strtok(str, s);

    while( token != NULL )
    {
       argv[tahv++] = token;
       token = strtok(NULL, s);
    }

    argv[tahv] = 0;


   for(n = 0; argv[n] != NULL; n++)
   {
	   printf("%s\n",argv[n]);
   }
   return(0);
}
