#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0 if sucess
*/

int main(void)
{
	char *buff; /*The input*/
	pid_t pid; /*process id*/
	char **argv; /*The array of argument*/
	int stat = 0;

	while (1)
	{
		/*Get The Input*/
		buff = get_input(buff);
		if (buff == NULL)
		{
			free(buff);
			return (stat);
		}
		/*Create a process*/
		pid = fork();
		if (pid == 0)
		{
			/*Parse the input and put it in Array*/
			argv = parse_input(buff);
			if (!argv)
				continue;

			exec(argv);
			/*free The memory of Array*/
			freeArrStr(argv);
		
		}
		else
		{
			wait(NULL);
		}
		free(buff);
	}
	return (0);
}
