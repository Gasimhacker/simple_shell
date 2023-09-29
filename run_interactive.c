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
	char **commands = malloc(265 * sizeof(char *));
	int is_seperator, lines_count, i;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		lines_count = _getlines(commands);
		if (lines_count != 0)
		{
			for (i = 0; i < lines_count; i++)
			{
				is_seperator = check_separator(commands[i], head, shell_name);

				if (!is_seperator)
					search_execute(commands[i], head, shell_name);

			}
		}
	}
		free(commands);
}
