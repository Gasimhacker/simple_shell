#include "main.h"

/**
 * remove_starting_qoute - Remove the qoute found in the middle of the word
 * @str: A pointer to the qoute inside the word
 *
 * Return: void
 */
void remove_starting_qoute(char *str)
{
	while (*str)
	{
		*str = *(str + 1);
		str++;
	}
}

/**
 * close_qoutes - Locate the closing qoute
 * @str: The string to close its qoute
 * @qoute: The qoute is either '' or ""
 *
 * Return: A pointer to the character after the closing qoute
 */
char *close_qoutes(char *str, char qoute)
{

	remove_starting_qoute(str);

	while (str && *str)
	{
		if (*str == qoute)
		{
			*str = '\0';
			return (str + 1);
		}
		str++;
	}

	return (NULL);
}

/**
 * locate_non_delimiter - Increment the Pointer until a non delimiter
 *			  character is reached
 * @ptr: The pointer to increment
 * @delim: The delimiter string
 *
 * Return: A pointer to the first non delimiter character
 */
char *locate_non_delimiter(char *ptr, const char *delim)
{
	int i = 0;

	while (delim && delim[i] && ptr[i])
	{

		if (delim[i] == *ptr)
		{
			ptr++;
			i = 0;
			continue;
		}

		i++;
	}

	if (*ptr == '\0')
		return (NULL);

	return (ptr);
}

/**
 * locate_delimiter - Increment the Pointer until a delimiter
 *			  character is reached
 * @start: The pointer to increment
 * @delim: The delimiter string
 *
 * Return: A pointer to the first delimiter character
 */
char *locate_delimiter(char *start, const char *delim)
{
	int i = 0, j = 0;

	if (start == NULL)
		return (NULL);

	while (start[i])
	{
		if (start[i] == '\"' || start[i] == '\'')
		{
			start = close_qoutes(start + i, start[i]);
			i = 0;
		}

		/* Closing qoute not found */
		if (start == NULL)
			return (NULL);

		if (start[i] == delim[j++])
		{
			start[i] = '\0';
			return (start + i);
		}

		if (!delim[j])
		{
			j = 0;
			if (start[i] != '\0')
				i++;
		}
	}

	return (NULL);
}


/**
 * _strtok - Split the string into tokens
 * @str: The string to split
 * @delim: The string containing delimiters that
 *	   indicate an end of a word(token)
 *
 * Return: A pointer to the next token everytime it is called
 *	   On failure - NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *start;

	if (str != NULL)
	{
		str = locate_non_delimiter(str, delim);
		if (str == NULL)
			return (NULL);
	}
	else if (start != NULL)
	{
		str = start;
	}
	else
	{
		return (NULL);
	}

	start = locate_delimiter(str, delim);

	if (start != NULL)
		start = locate_non_delimiter(start + 1, delim);

	if (start && *start == '\0')
		start = NULL;

	if (*str == '\'' || *str == '\"')
		return (str + 1);

	return (str);
}
