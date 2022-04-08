#include "main.h"

/**
 * breakline - look for breaklines.
 * @str_line: given string.
 * Return: 0 when the string contains breaklines, 1 otherwise.
 **/

int breakline(char *str_line)
{
	int i = 0;

	while (str_line[i] != '\0')
	{
		if (str_line[i] != 10)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
