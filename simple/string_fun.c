#include "shell.h"

/**
 * _strlen - function to Know the length of string
 *
 * @str: The string
 *
 * Return: The length of string
*/

int _strlen(char *str)
{
	int len = 0;
	
	if (!str)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strdup - function that duplicat the string
 *
 * @str: The string while duplicat
 *
 * Retrun: The pointer the new string
*/

char *_strdup(char *str)
{
	char *nstr;
	int size, i = 0;

	size = _strlen(str);
	nstr = malloc(sizeof(*str) * size + 1);
	if (nstr == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (; i < size; i++)
		nstr[i] = str[i];
	return (nstr);
}
