#include "main.h"

/**
 * _getenv - searches the environment list to find
 * the environment variable "str".
 * @str: name of the enviroment variable to search. M.A.E.S.
 * Return: pointer to the corresponding value string or NULL othervise
 **/

char *_getenv(char *str)
{
	unsigned int i = 0, j = 0, k = 0, lenvar = 0, lenenv = 0;
	char *envvar = NULL, *envval = NULL;

	if (str != NULL)
	{
		lenvar = _strlen(str);
		while (environ[i] != NULL)
		{
			lenenv = _strlen(environ[i]);
			envvar = malloc(sizeof(char) * (lenvar + 1));
			if (envvar == NULL)
				return (NULL);
			envval = malloc(sizeof(char) * (lenenv - 1 - lenvar + 1));
			if (envval == NULL)
			{
				free(envvar);
				return (NULL);
			}
			j = 0;
			while (j < lenvar)
			{
				envvar[j] = environ[i][j], j++;
			}
			envvar[j] = '\0';
			if (_strcmp(str, envvar) == 0)
			{
				j++;
				while (environ[i][j])
				{
					envval[k] = environ[i][j];
					j++, k++;
				}
				envval[k] = '\0', free(envvar);
				return (envval);
			}
			free(envval), free(envvar);
		i++;
		}
	}
	return (NULL);
}

/**
 * printenv - prints the environment variables list.
 **/

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

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * usage setenv VARIABLE VALUE.
 * @name: name of the enviroment variable to set.
 * @value: value of the variable.
 * @overwrite: when is 1 - if the variable already exist overwrite its value.
 * when is 0 don't. In both cases name was previously undefined,
 * it will be appended to the table. M.A.E.S.
 * Return: 0 if function succes -1 if it fail.
 **/

int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int i = 0, lenname = 0, lenvalue = 0;
	char *getenv = NULL;

	getenv = _getenv((char *)name);
	if (getenv == NULL)
	{
		lenname = _strlen((char *)name);
		lenvalue = _strlen((char *)value);
		while (environ[i] != NULL)
		{
			i++;
		}
		environ[i] = malloc(sizeof(char) * (lenname + 1 + lenvalue + 1));
		if (environ[i] == NULL)
			return (-1);
		environ[i] = _strcat((char *)name, "=");
		environ[i] = _strcat(environ[i], (char *)value);
		i++;
		environ[i] = NULL;
		return (0);
	}
	else
	{
		if (overwrite == 1)
		{
			free(getenv);
			return (overwrite_env(name, value));
		}
		else
			return (0);
	}
}

/**
 * overwrite_env - modify the value of an existent enviroment variable.
 * @name: name of the enviroment variable to set.
 * @value: value of the variable.
 * it will be appended to the table. M.A.E.S.
 * Return: 0 if function succes -1 if it fail.
 **/

int overwrite_env(const char *name, const char *value)
{
	unsigned int i = 0, j = 0, lenvar = 0, lenenv = 0;
	char *envvar = NULL;

	if (name != NULL && value != NULL)
	{
		lenvar = _strlen((char *)name);
		while (environ[i] != NULL)
		{
			lenenv = _strlen((char *)value);
			envvar = malloc(sizeof(char) * (lenvar + 1));
			if (envvar == NULL)
				return (-1);
			j = 0;
			while (j < lenvar)
			{
				envvar[j] = environ[i][j], j++;
			}
			envvar[j] = '\0';
			if (_strcmp((char *)name, envvar) == 0)
			{
				environ[i] = calloc(1, (sizeof(char) * (lenvar + 1 + lenenv + 1)));
				if (environ[i] == NULL)
				{
					free(envvar);
					return (-1);
				}
				_strcat(environ[i], envvar);
				_strcat(environ[i], "=");
				_strcat(environ[i], (char *)value);
				free(envvar);
				return (0);
			}
			free(envvar);
		i++;
		}
	}
	return (-1);
}
