#include "main.h"

/**
 * iscommand - verify if the input is an executable file in the path.
 * @args: list of arguments obtained from the tokenized string input.
 * Return: return full path where the executable file was found
 * or NULL otherwise.
**/

char *iscommand(char **args)
{
	int i = 0, j = 0;
	char *str_path = NULL, *file_path = NULL;
	char **path = NULL;
	struct stat st;

	str_path = _getenv("PATH");
	path = stringtok(str_path, ":");
	while (path[i] != NULL)
	{
		file_path = calloc(3, (sizeof(char) *
		((_strlen(path[i])) + (_strlen(args[j])) + 2)));
		if (file_path == NULL)
		{
			free(path);
			free(str_path);
			return (NULL);
		}
		_strcat(file_path, path[i]);
		_strcat(file_path, "/");
		_strcat(file_path, args[j]);
		if (stat(file_path, &st) == 0)
		{
			free(path);
			free(str_path);
			return (file_path);
		}
		i++;
	free(file_path);
	}
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(str_path);
	free(path);
	return (NULL);
}
