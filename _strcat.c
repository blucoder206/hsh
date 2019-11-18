#include "holberton.h"
/**
* _strcat - concatenate two strings
* @src: source
* @dest: destination
* Return: dest
**/
char *_strcat(char *dest, char *src)
{
	int i, j, l;

	for (i = 0; dest[i] != 00; i++)
	{
	}
	for (j = 0; src[j] != 00; j++)
	{
	}
	for (l = 0; l < j; l++)
	{
	dest[i + l] = src[l];
	}
	return (dest);
}
