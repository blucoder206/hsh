#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"


int main (void) {
    char *str;
    size_t readed_bytes;
    const char s[2] = ":\n";
    char *token;
    char **argv;
    int tahv = 0, n, i = 0;

    list_path *head;
    str = _getenv("PATH");
    readed_bytes = (strlen(str));
    printf("readed_bytes-%lu , str-> %s\n", readed_bytes, str);

    argv = malloc(readed_bytes * sizeof(*argv));
    token = strtok(str, s);

    while( token != NULL )
    {
       argv[tahv++] = token;
       token = strtok(NULL, s);
    }

    argv[tahv] = 0;
    head = NULL;

    while(argv[i] != NULL)
    {
    add_node_end (&head, argv[i]);
    i++;
    }

    size_t mi_list = print_list(head);
    
   return(0);
}