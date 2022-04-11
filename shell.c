#include "main.h"
/**
 * main - simple shell entry point
 * Return: Always 0.
 **/

int main(void)
{
	int bytes_read = 0, loop = 0, exstat = 0;
	size_t size = 0;
	char *str_line = NULL;
	char **args = NULL;

	while (loop == 0)
	{
		signal(SIGINT, ctrlC);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&str_line, &size, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (breakline(str_line) == 0)
			continue;
		args = stringtok(str_line, " \t\n");
		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exstat = exit_status(args);
				if (exstat == 2)
					continue;
				free(str_line);
				exit(exstat);
			}
			if (builtin(args) == 1)
				continue;
			execarg(args);
			free(args);
		}
		else
			free(args);
	}
	free(str_line);
	return (0);
}
