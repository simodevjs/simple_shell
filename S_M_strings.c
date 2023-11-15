#include "main.h"

/**
 * _strlen - Calculate the len of string
 * @str: the pointer that points to string
 * Return: leng
*/

int _strlen(char *str)
{
	int leng = 0;

	while (*str != '\0')
	{
		str++;
		leng++;
	}
	return (leng);
}


/**
 * _strdup - its dups a string to an other
 * @str: the string
 * Return: buffer
 */
char *_strdup(char *str)
{
	int len = 0, j = 0;
	char *buffer;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (str[j] != '\0')
	{
		buffer[j] = str[j];
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

/**
 * _strcpy - it copies the string to an other.
 * @src: the source
 * @dest: The destination
 * Return: Success if the string is good.
*/

char *_strcpy(char *dest, char *src)
{
	int l = 0, i;

	while (src[l] != '\0')
		l++;
	for (i = 0; i <= l; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - it cocatinates  strings to each other
 * @dest: The destination.
 * @src: The source
 * Return: if Success.
 */

char *_strcat(char *dest, char *src)
{
	int b = 0;

	while (*dest != '\0')
	{
		dest++;
		b++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		b++;
		src++;
	}
	*dest = '\0';
	dest -= b;
	return (dest);
}

/**
 * _strcmp - it compares two strings
 * @s1: the string 1
 * @s2: the string 2
 * Return: it returns difference between them;
 */

int _strcmp(char *s1, char *s2)
{
	int cotz;

	cotz = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
		cotz = (int)*s1 - (int)*s2;
	}
	return (cotz);
}

