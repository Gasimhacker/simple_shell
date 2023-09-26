#include "main.h"

/**
 * is_equal - Check if the environment variable equals the passed name
 * @name: The name to search for
 * @environ_var: The current environment variable
 *
 * Return: The value of the environment variable
 *	   If the variable equals the name, or NULL if the
 *	   name and variable are not equal
 */
char *is_equal(char *environ_var, const char *name)
{
	int i = 0;

	while (name[i])
	{
		if (environ_var[i] != name[i])
			return (NULL);
		i++;
	}

	if (environ_var[i] == '=')
		return (environ_var + i + 1);

	return (NULL);
}

/**
 * _getenv - Get an invironment variable
 * @name: The name of the variable
 * @offset: If "name" is found this member will be
 *	    updated to contain the offset of the
 *	    variable inside the environmet array
 *
 * Return: The address of the variable
 *	   or NULL if the variable is not found
 */
char *_getenv(const char *name, int *offset)
{
	char *ptr;
	int i = 0;

	if (name == NULL)
		return (NULL);

	while (environ[i])
	{
		ptr = is_equal(environ[i], name);

		if (ptr)
		{
			*offset = i;
			return (ptr);
		}
		i++;
	}

	return (NULL);
}
