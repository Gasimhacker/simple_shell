#include "main.h"

/**
 * run_interactive - Execute the shell commands in the interactive mode
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void run_interactive(alias_t **head, char *shell_name)
{
	char **args, *full_path;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		args = create_args();

		if (args == NULL)
			continue;

		if (search_builtins(head, shell_name, args[0], args))
		{
			clean(args);
			continue;
		}

		full_path = find_file(args[0]);

		if (full_path == NULL)
		{
			cmd_not_found_msg(shell_name, args[0]);
			clean(args);
			continue;
		}

		execute(args, full_path);
	}

}


