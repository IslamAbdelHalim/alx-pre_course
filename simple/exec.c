#include "shell.h"

/**
 * exec - function that execute the command
 *
 * @argv: The array of string (commands)
*/

void exec(__attribute__((unused)) char **argv)
{
	int r;
	const char *buffer = argv[0];

	r = execve(buffer, argv, NULL);
	if (r == -1)
	{
		perror("./hsh");
		exit(1);
	}
}
