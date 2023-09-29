#include "main.h"

/**
 * handle_exit - Handle the exit routine
 * @shell_name: The name of the shell is used for printing error messages
 * @head: The head of the linked list that needs to be freed
 * @arg_num: The number of arguments passed to the exit command
 * @args: The arguments passed to the exit command
 *
 * Return: void
 */
void handle_exit(char *shell_name, alias_t **head, int arg_num, char **args)
{
	int *exit_status = get_exit_status();

	if (arg_num > 2)
		return;
	if (arg_num == 2)
		*exit_status = (_atoi(args[1]));

	if (*exit_status < 0 || (arg_num == 2 && _atoi(args[1]) == 0
				&& _strcmp(args[1], "0")))
	{
		wrong_exit_code_msg(shell_name, args[1]);
		*exit_status = 2;
	}

	clean(args);
	clean(environ);
	free_list(*head);
	exit(*exit_status & 255);
}

/**
 * handle_aliases - Handle the alias builtin
 * @head: The head of the linked list that needs to be freed
 * @arg_num: The number of arguments passed to the exit command
 * @args: The arguments passed to the exit command
 *
 * Return: void
 */
void handle_aliases(alias_t **head, int arg_num, char **args)
{
	if (arg_num == 1)
		print_aliases(head);
	else
	{
		arg_num = 1;
		while (args[arg_num])
		{
			if (_strchr(args[arg_num], '='))
				create_alias(head, args[arg_num]);
			else
				print_specific_alias(head, args[arg_num]);
			arg_num++;
		}
	}
}


/**
 * search_builtins - Check if the command passed is a builtin
 *		     and if it is a builtin execute it
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * @cmd_name: The name of the command
 * @args: The arguments list to pass to the handler functions
 *
 * Return: If builtin found - 1
 *	   Otherwise - 0
 */
int search_builtins(alias_t **head, char *shell_name,
		char *cmd_name, char **args)
{
	int i = 0;

	while (args[i])
		i++;

	if (_strcmp(cmd_name, "exit") == 0)
		handle_exit(shell_name, head, i, args);

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
	else if (_strcmp(cmd_name, "alias") == 0)
		handle_aliases(head, i, args);
	else
		return (0);
	return (1);
}
