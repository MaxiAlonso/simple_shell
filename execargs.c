#include "main.h"

/**
 * execarg - checks if the inuput read is valid, when it is
 * the function forks, create a new child and execute.
 * @args: list of arguments obtained from the tokenized string input.
 **/

void execarg(char **args)
{
	pid_t child_pid;
	int status, succes = 0;
	struct stat st;

	if (args[0][0] >= 'a' && args[0][0] <= 'z')
	{
		args[0] = iscommand(args);
		if (args[0] == NULL)
		{
			free(args[0]);
			return;
		}
		succes = 1;
	}
	if (stat(args[0], &st) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror(args[0]);
				free(args[0]);
				free(args);
				exit(-1);
			}
		}
		else
			wait(&status);
		if (succes == 1)
			free(args[0]);
	}
	else
	{
		write(STDOUT_FILENO, args[0], _strlen(args[0]));
		write(STDOUT_FILENO, ": not found\n", 12);
	}
}
