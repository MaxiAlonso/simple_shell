#include "main.h"

/**
  * stringtok - take a string and parse it
  * into tokens wich are stored in an array.
  * @str_line: string to be parsed.
  * @delimitator: separator used to parse.
  * Return: null terminated array with the tokenes.
**/

char **stringtok(char *str_line, const char *delimitator)
{
	char *token = NULL;
	int wc = 0, i = 0;
	char **args;

	while (str_line[i] != '\0')
	{
		if (str_line[i] != 32 && str_line[i] != 10
				       && str_line[i] != 58 && str_line[i] != 9)
		{
			while (str_line[i] != 32 && str_line[i] != 10 && str_line[i] != 9
					&& str_line[i] != 58 && str_line[i] != '\0')
			{
				i++;
			}
			wc++;
		}
		if (str_line[i] == '\0')
		{
			break;
		}
		i++;
	}
	args = malloc(sizeof(char *) * (wc + 1));
	if (args == NULL)
	{
		return (NULL);
	}
	i = 0;
	token = strtok(str_line, delimitator);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delimitator);
		i++;
	}
	args[i] = NULL;
	return (args);
}
