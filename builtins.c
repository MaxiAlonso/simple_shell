#include "main.h"
/**
 * builtin - look for a builtin and call the respective function.
 * @args: list of arguments obtained from the tokenized string input.
 * Return: 1 if is a builtin 0 otherwise.
 **/

int builtin(char **args)
{

	if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		free(args);
		return (1);
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		_setenv((const char *)args[1], (const char *)args[2], 1);
		free(args);
		return (1);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		free(args);
		return (1);
	}
	return (0);
}
