#include "main.h"


/**
 * search_builtins - Check if the command passed is a builtin
 *		     and if it is a builtin execute it
 * @cmd_name: The name of the command
 * @args: The arguments list to pass to the handler functions
 *
 * Return: If builtin found - 1
 *	   Otherwise - 0
 */
int search_builtins(char *cmd_name, char **args)
{
	int i = 0, *exit_status = get_exit_status();
	alias_t **head = get_head();

	while (args[i])
		i++;
	if (_strcmp(cmd_name, "exit") == 0)
	{
		if (i > 2)
			return  (-1);
		if (i == 2)
			*exit_status = (_atoi(args[1]));
		if (*exit_status < 0)
		{
			write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: -98\n", 36);
			*exit_status = 2;
		}
		clean(args);
		clean(environ);
		free_list(*head);
		exit(*exit_status & 255);
	}
	else if (_strcmp(cmd_name, "env") == 0)
		print_env();
	else if (_strcmp(cmd_name, "setenv") == 0)
	{
		if (i != 3)
			return  (-1);
		_setenv(args[1], args[2], 1);
	}
	else if (_strcmp(cmd_name, "unsetenv") == 0)
	{
		if (i != 2)
			return  (-1);
		_unsetenv(args[1]);
	}
	else if (_strcmp(cmd_name, "cd") == 0)
		change_directory(args[1]);
	else
		return (0);
	return (1);
}
