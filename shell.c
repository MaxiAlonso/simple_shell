#include "main.h"

int main(void)
{
	int bytes_read = 0, loop = 0;
	size_t size = 0;
	char *str_line = NULL, *ex = "exit", *eof = "end-of-file", *env = "env";
	char **args = NULL;

	while (loop == 0)
	{
		signal(SIGINT, ctrlC);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		else
			loop++;
		bytes_read = getline(&str_line, &size, stdin);
		if (bytes_read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = stringtok(str_line, " \n");
		if (args[0] != NULL)
		{
			if (_strcmp(args[0], eof) == 0 || _strcmp(args[0], ex) == 0)
			{
				free(args);
				break;
			}
		}
		if (_strcmp(str_line, env) == 0)
		{
			printenv();
			continue;
		}
		execarg(args);
		free(args);
	}
	free(str_line);
	return (0);
}
