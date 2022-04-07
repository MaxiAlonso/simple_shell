#include "main.h"

/**
 * _strlen - returns the length of a string.
 * Return: returns the lenght of a string.
 * @s: pointer to a char
 **/

int _strlen(char *s)
{
	int len;

	len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
}

/**
 *_strcat - concatenates two strings.
 * @src: string 2
 * @dest: string 1
 * Return: concatenated string
 **/

char *_strcat(char *dest, char *src)
{
	int i, a;

	i = 0;
	a = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[a])
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer (-) s1<s2, 0 s1=s2 and (+) s1>s2
 **/

int _strcmp(char *s1, char *s2)
{
	int i, a;

	i = 0;
	a = 0;

	if (s1[0] == s2[0])
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			i++;
		}
	}
	a = (s1[i] - '0') -  (s2[i] - '0');
	return (a);
}
