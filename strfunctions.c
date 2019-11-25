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
/**
 * _strlen - Returns the length of a string
 * @s: pointer type char
 * Return: The program will return the number of characters of *s (the length)
 **/
int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != 00; i++)
        {
        }
        return (i);
}