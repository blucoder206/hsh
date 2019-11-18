#include <stdio.h>
/**
 * main - prints all arguments without argc
 * @ac: vector size
 * @argv: elements of vector
 * Return: nothing
 */
int main(int ac, char **av)
{
	int i;

	for (i = 0; av[i] != 00; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
