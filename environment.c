#include "main.h"

char *_getenv(char *str)
{
	unsigned int i = 0, j = 0, k = 0, lenenv = 0, lenstr = 0;
	char *envstr = NULL, *envvar = NULL;

	if (str != NULL)
	{
		lenstr = _strlen(str);
		while (environ[i] != NULL)
		{
			lenenv = _strlen(environ[i]);
			envstr = malloc(sizeof(char) * (lenstr + 1));
			if (envstr == NULL)
				return (NULL);
			envvar = malloc(sizeof(char) * (lenenv - lenstr + 1));
			if (envvar == NULL)
			{
				free(envstr);
				return (NULL);
			}
			j = 0;
			while (j < lenstr)
			{
				envstr[j] = environ[i][j], j++;
			}
			envstr[j] = '\0';
			if (_strcmp(str, envstr) == 0)
			{
				j++;
				while (environ[i][j])
				{
					envvar[k] = environ[i][j];
					j++, k++;
				}
				envvar[k] = '\0', free(envstr);
				return (envvar);
			}
			free(envvar), free(envstr);
		i++;
		}
	}
	return (NULL);
}

void printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
