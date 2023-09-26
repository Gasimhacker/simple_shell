#include "main.h"


/**
 * find_file - check if the file is present
 * @file_name: The file name
 *
 * Return: If the file is found - a pointer to the full path
 *	   Otherwise - NULL
 */
char *find_file(char *file_name)
{
	int i = 0, offset;
	struct stat st;
	char *path = _getenv("PATH", &offset);
	char **dir;
	char *full_path;

	if (file_name == NULL || (path && _strcmp(path, "") == 0))
		return (NULL);

	if (stat(file_name, &st) == 0 && _strchr(file_name, '/'))
	{
		full_path = _strdup(file_name);
		return (full_path);
	}

	dir = split_string(path, ":");

	while (dir && dir[i])
	{
		full_path = cat_with_delimiter(dir[i], "/", file_name);
		if (stat(full_path, &st) == 0)
		{
			clean(dir);
			return (full_path);
		}
		else
		{
			free(full_path);
			i++;
		}
	}

	clean(dir);

	return (NULL);
}
