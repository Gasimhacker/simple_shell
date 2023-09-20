#include "main.h"

/**
 * search_env - Search for the variable inside the environment
 * @env_var: The variable to search
 *
 * Return: If the variable is found - a copy of its value
 *	   otherwise - a copy of an empty string
 */
char *search_env(char *env_var)
{
	int offset;
	char *value = _getenv(env_var, &offset);

	if (value == NULL)
		return (_strdup(""));
	return (_strdup(value));
}

/**
 * replace_string - Replace an old string with a new one
 * @old_str: a pointer to the old string
 * @new_str: The new string
 *
 * Return: void
 */
void replace_string(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
}

/**
 * search_cmd_expansion - Search for variable expansions
 * @args: The array of arguments
 *
 * Return: void
 */
void search_cmd_expansion(char **args)
{
	pid_t my_pid;
	int i = 0;
	int *exit_code;
	char *str_expansion;

	while (args[i])
	{
		if (_strcmp(args[i], "$?") == 0)
		{
			exit_code = get_exit_status();
			str_expansion = _itoa(*exit_code);
			replace_string(args + i, str_expansion);
		}
		else if (_strcmp(args[i], "$$") == 0)
		{
			my_pid = getpid();
			str_expansion = _itoa(my_pid);
			replace_string(args + i, str_expansion);
		}
		else if (_strchr(args[i], '$') == args[i])
		{
			str_expansion = search_env(args[i] + 1);
			replace_string(args + i, str_expansion);
		}
		i++;
	}
}


/**
 * create_args - Create the arguments list
 *
 * Return: The arguments list
 */
char **create_args(void)
{
	char *buff = NULL, **args;
	size_t n;

	if (getline(&buff, &n, stdin) == -1)
		exit(1);

	args = split_string(buff, " \n");
	search_cmd_expansion(args);
	free(buff);

	return (args);
}
