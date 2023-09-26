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
	char *buff = null;
    int is_seperator;
    size_t n;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
        
	    if (getline(&buff, &n, stdin) == -1)
		    exit(1);
        
        is_seperator = check_separator(buff,head,shell_name);

        if (!is_seperator)
            search_execute(buff,head,shell_name);
	}
	free(buff);

}


