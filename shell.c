#include "main.h"

/**
 * main - Super simple shell
 * @argc: The arguments count
 * @argv: The arguments vector
 *
 * Return: Always the last exit status.
 */
int main(int __attribute__((unused))argc, char **argv)
{
	int *exit_status = get_exit_status();
	alias_t *head = NULL;

	copy_to_heap();

	if (!isatty(STDIN_FILENO))
		run_non_interactive(&head, argv[0]);
	else
		run_interactive(&head, argv[0]);

	clean(environ);

	return (*exit_status);
}
