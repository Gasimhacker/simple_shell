#include "main.h"

/**
 * run_non_interactive - Execute the shell commands in
 *			 the non interactive mode
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void run_non_interactive(alias_t **head, char *shell_name)
{
	char *full_path, **args = NULL;

	args = create_args();

	if (args == NULL)
		return;

	if (search_builtins(head, shell_name, args[0], args))
	{
		clean(args);
		return;
	}

	full_path = find_file(args[0]);

	if (full_path == NULL)
	{
		cmd_not_found_msg(shell_name, args[0]);
		clean(args);
		exit(127);
	}

	execve(full_path, args, environ);
}

