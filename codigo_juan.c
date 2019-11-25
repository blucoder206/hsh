#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
typedef struct my_path
{
        char *str;
        struct my_path *next;
} list_path;
extern char **environ;
char *_getenv(char *name)
{
        int i, len_value;
        char *copy_name, *value;
        printf("name = **%s**\n", name);
        copy_name = malloc(strlen(name) + 2);
        strcpy(copy_name,name);
        printf("copy_name = **%s** and name = **%s**\n", copy_name, name);
        value = strcat(copy_name, "=");
        printf("value = **%s**\n", value);
        len_value = strlen(value);
        printf("len_value = **%d**\n", len_value);
        for (i = 0; environ[i] != NULL; i++)
        {
                printf("environ[%d] = **%s**\n", i, environ[i]);
                if (strncmp(value, environ[i], len_value) == 0)
                {
                        printf("\nvalue = **%s**,\nenviron[%d] = **%s**,\nlen_value = **%d**\n", value, i, environ[i], len_value);
                        free(copy_name);
                        printf("free copy_name in progress....\n");
                        printf("return (environ[i] + len_value) = **%s**\n", environ[i] + len_value);
                        return (environ[i] + len_value);
                }
        }
        printf("\n");
}
/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: address to a list_t head
* @str: string to add the list_t
* Return: the address of the new element, or NULL if it failed
**/
list_path *add_node_end(list_path **head, char **array_path)
{
        int i = 0;
	list_path *new = NULL;
	list_path *pointer = NULL;
        while(array_path[i] != NULL)
        {
		if (head == NULL)
		{
			return (NULL);
		}
                new = malloc(sizeof(list_path));
                if (new == NULL)
                {
                        return (NULL);
                }
                new->str = array_path[i];
                new->next = NULL;
		pointer = *head;
                if (pointer == NULL)
                {
                         *head = new;
                         //return (new);
		}
                else
		{
		  	while (pointer->next != NULL)
			{
		 		pointer = pointer->next;
			}
			pointer->next = new;
		}
                i++;
        }
        return (*head);
}
/**
 * print_list - prints all the elements of a list
 * @head: a pointerr to the list
 *
 * Return: The number of nodes
 */
size_t print_list(list_path *head)
{
	/*counter variable*/
	size_t i = 0;
	const list_path *tmp;
	/*Do not change the head reference.*/
	tmp = head;
	/* if (!tmp) */
	if (tmp == NULL)
		return (0);
	/* while (tmp) */
	while (tmp != NULL)
	{
		if (tmp->str != NULL)
			printf("node[u]: **%s**\n", tmp->str);
		else
			printf("node[0]: (nil)\n");
		tmp = tmp->next;
		i++;
	}
	return (i);
}
int main (void) {
        char *str;
        size_t readed_bytes;
        const char s[2] = ":\n";
        char *token;
        char **argv;
        int tahv = 0, n;
        list_path *head;
        str = _getenv("PATH");
        printf("\nstr = **%s**\n", str);
        readed_bytes = (strlen(str));
        printf("readed_bytes = **%lu**\n", readed_bytes);
        //argv = malloc(readed_bytes * sizeof(* argv));
        argv = malloc((readed_bytes + 2) * sizeof(* argv));
        token = strtok(str, s);
        printf("token = **%s**\n", token);
        while( token != NULL )
        {
                argv[tahv++] = token;
                token = strtok(NULL, s);
        }
        argv[tahv] = NULL;
        printf("\n");
        int in= 0;
        while (argv[in] != NULL)
        {
            printf("argv[%d] = **%s**\n", in, argv[in]);
            in++;
        }
	printf("\n");
        head = NULL;
        add_node_end (&head, argv);
	print_list(head);
        return(0);
}