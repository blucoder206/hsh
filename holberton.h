#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name);

typedef struct list_path
{
	char *str;
	struct list_path *next;
} list_path;

list_path *add_node_end(list_path **head, char *array_path);
size_t print_list(const list_path *h);
#endif
