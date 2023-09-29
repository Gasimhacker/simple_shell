#include "main.h"


/**
 * cat_with_delimiter - Create an absolute path
 * @first_name: The first nam
 * @delim: The delimiter between the two names
 * @second_name: The second name
 *
 * Return: A duplicate containing the concatenated word
 */
char *cat_with_delimiter(const char *first_name,
		char *delim, const char *second_name)
{
	int len1 = _strlen(first_name);
	int len2 = _strlen(second_name);
	char *new_var;

	new_var = malloc((len1 + len2 + 2) * sizeof(char));
	_strcpy(new_var, first_name);
	_strcpy(new_var + len1, delim);
	_strcpy(new_var + len1 + 1, second_name);

	return (new_var);
}


/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-' && num == 0)
		{
			sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = (num * 10) + (*s - '0');
		}
		else if (num > 0)
		{
			break;
		}

	} while (*s++);

	return (num * sign);
}

/**
 * count_digits - count the number of digits in a number
 * @num: The number to count its digits
 *
 * Return: The number of digits
 */
int count_digits(int num)
{
	int digits = 1;

	while (num / 10 > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * _itoa - Convert a positive integer to string
 * @num: The number to convert
 *
 * Return: A pointer to the string created, or NULL on failure
 */
char *_itoa(int num)
{
	int digits;
	char *str;

	digits = count_digits(num);

	str = malloc((digits + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	str[digits--] = '\0';

	for ( ; digits >= 0; digits--)
	{
		str[digits] = ((num % 10) + '0');
		num /= 10;
	}

	return (str);
}

/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter)
{
	char **words = NULL;
	char *str_copy = _strdup(str);
	char *token = _strtok(str_copy, delimiter);
	int count = 1;


	if (str == NULL)
		return (NULL);


	words = malloc(sizeof(char *));

	if (!words)
		return (NULL);

	words[0] = NULL;

	while (token != NULL)
	{
		words = realloc(words, (count + 1) * sizeof(char *));

		if (!words)
			return (NULL);

		words[count - 1] = _strdup(token);
		words[count] = NULL;

		count++;
		token = _strtok(NULL, delimiter);
	}

	free(str_copy);

	return (words);
}
