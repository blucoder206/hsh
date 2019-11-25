#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "holberton.h"

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