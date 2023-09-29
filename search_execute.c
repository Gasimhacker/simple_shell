#include "main.h"

/**
 * search_execute - Serach for the command and execute it if found
 * @command: The command tobe executed
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void search_execute(char *command, alias_t **head, char *shell_name)
{
	char **args, *full_path;

	args = create_args(command);

	if (args == NULL)
		return;

	if (search_builtins(head, shell_name, args[0], args))
	{
		clean(args);
		exit(EXIT_SUCCESS);
	}

	full_path = find_file(args[0]);

	if (full_path == NULL)
	{
		cmd_not_found_msg(shell_name, args[0]);
		clean(args);
		exit(127);
	}

	execute(args, full_path);
}
