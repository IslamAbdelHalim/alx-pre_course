#include "shell.h"

/**
 * get_input - function to get input and put it into array
 *
 * Return: Array of argument
*/

char *get_input()
{
	char *buff;
	size_t n = BUFF_SIZE;
	ssize_t x;
	char *newline;

	/*Print The Prompt*/
	if (isatty(0))
		write(1, "#shell$ ", 8);

	/*Create array to store The input*/
	buff = malloc(sizeof(char) * n);
	if (buff == NULL)
	{
		perror("Error\n");
		exit(1);
	}
	/*Get the input*/
	x = getline(&buff, &n, stdin);

	if (x == -1)
	{
		write(1, "\n", 1);
		free(buff);
		return (NULL);
	}

	/*To Delete The newline*/
	newline = strchr(buff, '\n');
	if (newline != NULL)
		*newline = '\0';
	/*return the input*/
	return (buff);
}
