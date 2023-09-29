#include "main.h"

/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);

}

/**
 * _strdup - Copy a string given as a parameter into
 *		  a newly allocated memory space
 * @str: The string to be copied
 *
 * Return: A pointer to the duplicated string, NULL otherwise
 */
char *_strdup(const char *str)
{
	unsigned int i;
	unsigned int len;
	char *p;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	p = malloc((len + 1) * sizeof(char));

	if (p == NULL)
		return (p);

	for (i = 0; i <= len; i++)
		*(p + i) = *(str + i);

	return (p);
}

/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The string to compare with the first
 * Return: Zero if both strings are identical,
 *	   greater than zero when the matching
 *	   character of left string has greater
 *	   ASCII value than the character of
 *	   the right string, less than zero
 *	   when the left character has a smaller
 *	   value.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;

	return (s1[i] - s2[i]);
}

/**
 * _strchr - Locate a character in a string
 * @s: The string to be searched
 * @c: The character to find
 *
 * Return: A pointer to the first occurrence of the character c
 *	   in the string s, or NULL if the character is
 *	   not found
 */
char *_strchr(char *s, char c)
{
	for ( ; *s; s++)
	{
		if (*s == c)
		{
			return (s);
		}

	}
	if (c == '\0')
	{
		return (s);
	}

	return (0);
}
