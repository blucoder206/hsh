#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"
 

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




