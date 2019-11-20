#include "holberton.h"
/**
* _strcpy - copy the string src to string dest
* @src: string source
* @dest: string dest
* Return: the string dest
**/
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';
	return (dest);
}
