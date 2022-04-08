#include "main.h"
/**
 * exit_status - exit with status read as command.
 * @str: status in string format to be converted to an integer..
 */
int exit_status(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if (status < 0)
		{
			free(args);
			perror(NULL);
			return (-1);
		}
		else
		{
			free(args[0]);
			free(args);
			exit(status);
		}
	}
	else
	{
		free(args[0]);
		free(args);
		exit(0);
	}
}
