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

	char *buff = NULL;
    int is_seperator;
    size_t n;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
        
	    if (getline(&buff, &n, stdin) == -1)
		    exit(1);
        
        is_seperator = check_separator(buff);

        if (is_seperator)
            continue;
        else
            search_execute(buff);
            
        free(buff);
	}

}


