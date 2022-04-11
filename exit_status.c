#include "main.h"
/**
 * exit_status - exit with status read as command.
 * @args: status in string format to be converted to an integer.
 * Return: -1 when status is an ilegal number 0 otherwise.
 */

int exit_status(char **args)
{
	int exstat = 0, i = 0;

	if (args[1] != NULL)
	{
		exstat = _atoi(args[1]);

		while (args[1][i] != '\0')
		{
			if (args[1][i] < '0' || args[1][i] > '9')
			{
				write(STDOUT_FILENO, args[0], _strlen(args[0]));
				write(STDOUT_FILENO, ": Illegal number: ", 19);
				write(STDOUT_FILENO, args[1], _strlen(args[1]));
				write(STDOUT_FILENO, "\n", 1);
				free(args);
				return (2);
			}
		i++;
		}
		free(args);
		return (exstat);
	}
	else
	{
		exstat = EXIT_SUCCESS;
		free(args);
		return (exstat);
	}
}
