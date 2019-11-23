#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
extern char **environ;
 
typedef struct list_path
{
        char *str;
        struct list_path *next;
} list_path;
 
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
 
list_path *add_node_end(list_path **head, char *array_path)
{
    list_path *new;
    list_path *pointer;

        if (head == NULL)
        {
                return (NULL);
        }
     
        new = malloc(sizeof(list_path));
	
        if (new == NULL)
        {
            return (NULL);
        }
	
        new->str = array_path;
        new->next = NULL;
	
        if (*head == NULL)
        {
                *head = new;
                return (new);
        }
    else
    {
        pointer = *head;
	
        while (pointer->next != NULL)
        {
                pointer = pointer->next;
        }
        pointer->next = new;
    }

        return (new);
}

size_t print_list(const list_path *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
		{
			printf("%s\n", h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		h = h->next;
		n++;
	}

	return (n);
}

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
